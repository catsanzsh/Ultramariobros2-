// Constants
#define MERMAID_JUMP_FORCE 50.0f
#define GRAVITY -4.0f
#define MERMAID_DETECTION_RADIUS 300.0f

// Helper function to calculate distance between mermaid and Mario
float distanceToMario(struct Object *o) {
    return sqrtf(powf(o->oPosX - gMarioObject->oPosX, 2) +
                 powf(o->oPosY - gMarioObject->oPosY, 2) +
                 powf(o->oPosZ - gMarioObject->oPosZ, 2));
}

// Initialize the mermaid's behavior
void bhv_mermaid_init(void) {
    o->oGravity = GRAVITY; // Set gravity for the mermaid
    o->oFriction = 0.9f;   // Friction for realistic movement
    o->oVelY = 0;          // Initialize the vertical velocity
    o->oAction = 0;        // Mermaid starts in idle state
}

// Main behavior loop for the mermaid
void bhv_mermaid_loop(void) {
    float distToMario = distanceToMario(o);
    
    // Mermaid is idle and waiting for Mario to approach
    if (o->oAction == 0) {
        if (distToMario < MERMAID_DETECTION_RADIUS) {
            // If Mario is close, start jumping towards him
            o->oVelY = MERMAID_JUMP_FORCE;
            o->oAction = 1; // Switch to jumping state
        }
    }
    
    // Mermaid is jumping
    if (o->oAction == 1) {
        // Apply gravity
        o->oVelY += o->oGravity;
        o->oPosY += o->oVelY;
        
        // Check for collision with Mario
        if (distToMario < 50.0f && abs(o->oPosY - gMarioObject->oPosY) < 50.0f) {
            // Mermaid lands on Mario: Apply damage or effect
            mario_take_damage();
            o->oAction = 0; // Return to idle state
        }
        
        // If the mermaid reaches the ground, reset the jump
        if (o->oPosY <= find_floor_height(o->oPosX, o->oPosY, o->oPosZ)) {
            o->oPosY = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
            o->oVelY = 0;  // Stop falling
            o->oAction = 0; // Back to idle
        }
    }
}

// Behavior script array for the mermaid
const BehaviorScript bhvMermaidJump[] = {
    BEGIN(OBJ_LIST_GENACTOR), // Object is a general actor
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, mermaid_seg6_anims_0601A00C),
    ANIMATE(0),
    CALL_NATIVE(bhv_mermaid_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mermaid_loop),
    END_LOOP(),
};

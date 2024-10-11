#include <stdio.h>
#include <stdbool.h>

// Define Mario's properties
typedef struct {
    float x, y;          // Position
    float velocityX;     // Velocity in the X direction
    float velocityY;     // Velocity in the Y direction (jumping)
    bool onGround;       // Is Mario on the ground?
} Mario;

// Initialize Mario
void initMario(Mario* mario) {
    mario->x = 0.0f;
    mario->y = 0.0f;
    mario->velocityX = 0.0f;
    mario->velocityY = 0.0f;
    mario->onGround = true;
}

// Handle player input
void handleInput(Mario* mario) {
    char input;
    printf("Enter command (a: left, d: right, j: jump): ");
    scanf(" %c", &input); // Read user input

    if (input == 'a') { // Move left
        mario->velocityX = -1.0f; // Move left
    } else if (input == 'd') { // Move right
        mario->velocityX = 1.0f; // Move right
    } else if (input == 'j' && mario->onGround) { // Jump
        mario->velocityY = 5.0f; // Jump velocity
        mario->onGround = false;  // Set to not on the ground
    } else {
        mario->velocityX = 0.0f; // Stop moving
    }
}

// Update Mario's position
void updateMario(Mario* mario) {
    mario->x += mario->velocityX;

    // Simple gravity effect
    if (!mario->onGround) {
        mario->velocityY -= 0.1f; // Apply gravity
        mario->y -= mario->velocityY; // Move up/down based on velocityY

        // Check if Mario lands
        if (mario->y <= 0.0f) { // Assuming ground level is at y = 0
            mario->y = 0.0f; // Reset to ground level
            mario->onGround = true; // Mario is on the ground
            mario->velocityY = 0.0f; // Reset jump velocity
        }
    }
}

// Main game loop
int main() {
    Mario mario;
    initMario(&mario);

    while (true) {
        handleInput(&mario); // Handle user input
        updateMario(&mario); // Update Mario's position
        printf("Mario's position: (%.2f, %.2f)\n", mario.x, mario.y); // Print position
    }

    return 0;
}

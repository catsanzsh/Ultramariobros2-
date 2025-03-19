#include "oneg.h"

// Define HUD element properties
typedef struct {
    OneGTexture* texture;
    float x, y;
    float width, height;
} HUDItem;

// Example HUD item
HUDItem hudItem = { hudTexture, 10.0f, 10.0f, 100.0f, 20.0f };

// Function to render the HUD
void renderHUD(OneGRenderer* renderer) {
    OneG_RenderTexture(renderer, hudItem.texture, hudItem.x, hudItem.y, hudItem.width, hudItem.height);
}

// Optimized HUD rendering logic for better performance
void optimizedRenderHUD(OneGRenderer* renderer) {
    // Render the HUD item
    OneG_RenderTexture(renderer, hudItem.texture, hudItem.x, hudItem.y, hudItem.width, hudItem.height);
}

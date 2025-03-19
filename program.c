#include <stdio.h>
#include "oneg.h" // Your custom graphics library header

typedef struct {
    OneGTexture* texture;
    float x, y;
    float width, height;
} HUDItem;

int main() {
    // Initialize the graphics library
    OneG_Init();

    // Create a renderer object
    OneGRenderer* renderer = OneG_CreateRenderer();

    // Load a texture for the HUD
    HUDItem hudItem = { OneG_LoadTexture("path/to/hud_texture.bmp"), 10.0f, 10.0f, 100.0f, 20.0f };

    // Main game loop
    while (OneG_IsRunning()) {
        // Clear the screen
        OneG_Clear(renderer);

        // Render the HUD
        OneG_OptimizedRenderTexture(renderer, hudItem.texture, hudItem.x, hudItem.y, hudItem.width, hudItem.height);

        // Present the rendered frame
        OneG_Present(renderer);

        // Handle system events
        OneG_HandleEvents();
    }

    // Cleanup resources
    OneG_DestroyTexture(hudItem.texture);
    OneG_DestroyRenderer(renderer);

    // Quit the graphics library
    OneG_Quit();

    return 0;
}
#include <stdio.h>
#include "oneg.h" // Your custom graphics library header

typedef struct {
    OneGTexture* texture;
    float x, y;
    float width, height;
} HUDItem;

int main() {
    // Initialize the graphics library
    OneG_Init();

    // Create a renderer object
    OneGRenderer* renderer = OneG_CreateRenderer();

    // Load a texture for the HUD
    HUDItem hudItem = { OneG_LoadTexture("path/to/hud_texture.bmp"), 10.0f, 10.0f, 100.0f, 20.0f };

    // Main game loop
    while (OneG_IsRunning()) {
        // Clear the screen
        OneG_Clear(renderer);

        // Render the HUD
        OneG_OptimizedRenderTexture(renderer, hudItem.texture, hudItem.x, hudItem.y, hudItem.width, hudItem.height); // Optimized rendering

        // Present the rendered frame
        OneG_Present(renderer);

        // Handle system events
        OneG_HandleEvents();
    }

    // Cleanup resources
    OneG_DestroyTexture(hudItem.texture);
    OneG_DestroyRenderer(renderer);

    // Quit the graphics library
    OneG_Quit();

    return 0;
}

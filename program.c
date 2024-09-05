int main() {
    // Initialize OneG
    OneG_Init();

    // Create renderer
    OneGRenderer* renderer = OneG_CreateRenderer();

    // Load HUD textures
    hudTexture = loadTexture("path/to/hud_texture.bmp");

    // Create HUD item
    HUDItem hudItem = { hudTexture, 10.0f, 10.0f, 100.0f, 20.0f };

    // Main loop
    while (OneG_IsRunning()) {
        // Clear the screen
        OneG_Clear(renderer);

        // Render HUD
        renderHUD(renderer, &hudItem);

        // Present the renderer
        OneG_Present(renderer);

        // Handle events and other game logic
        OneG_HandleEvents();
    }

    // Clean up
    OneG_DestroyTexture(hudTexture);
    OneG_DestroyRenderer(renderer);
    OneG_Quit();

    return 0;
}

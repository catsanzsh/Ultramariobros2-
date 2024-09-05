extern "C" void draw_hud_element();

int main() {
    // Initialize OneG and load textures
    // ...

    // Main loop
    while (OneG_IsRunning()) {
        // Clear the screen
        OneG_Clear(renderer);

        // Call MIPS assembly function to handle specific rendering
        draw_hud_element();

        // Render HUD
        renderHUD(renderer, &hudItem);

        // Present the renderer
        OneG_Present(renderer);

        // Handle events and other game logic
        OneG_HandleEvents();
    }

    // Clean up
    // ...

    return 0;
}

#include <oneg.h>  // Include OneG header

// Function to load texture
OneGTexture* loadTexture(const char* file) {
    OneGTexture* texture = OneG_LoadTexture(file);
    if (!texture) {
        printf("Error loading texture: %s\n", file);
    }
    return texture;
}

// Load HUD textures
OneGTexture* hudTexture = loadTexture("path/to/hud_texture.bmp");

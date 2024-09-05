// Define HUD element properties
typedef struct {
    OneGTexture* texture;
    float x, y;
    float width, height;
} HUDItem;

// Example HUD item
HUDItem hudItem = { hudTexture, 10.0f, 10.0f, 100.0f, 20.0f };

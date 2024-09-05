int main() {
    OneG_Init();
    OneGRenderer* renderer = OneG_CreateRenderer();
    HUDItem hudItem = { loadTexture("path/to/hud_texture.bmp"), 10.0f, 10.0f, 100.0f, 20.0f };

    while (OneG_IsRunning()) {
        OneG_Clear(renderer);
        renderHUD(renderer, &hudItem);
        OneG_Present(renderer);
        OneG_HandleEvents();
    }

    OneG_DestroyTexture(hudItem.texture);
    OneG_DestroyRenderer(renderer);
    OneG_Quit();

    return 0;
}

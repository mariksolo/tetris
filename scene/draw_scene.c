#include "../common.h"
#include "../structs.h"
#include "../draw.h"

void draw_scene(struct App app)
{
    SDL_SetRenderDrawColor(app.renderer, 40, 40, 40, 255);
    SDL_RenderClear(app.renderer);

    SDL_Color color = {10, 10, 10, 255};

    int y = 200;
    struct Position position = {50, y};
    for (int x = 200; x < SCENE_WIDTH * BLOCK_SIZE; x += BLOCK_SIZE)
    {
        position.x = x;
        draw_block(app, position, color);
    }
}
#include "../common.h"
#include "../structs.h"
#include "../draw.h"
#include "position.h"
#include "../gameplay/Piece.h"
#include "../gameplay/draw_piece.h"

void draw_scene(struct App app)
{
    SDL_SetRenderDrawColor(app.renderer, 40, 40, 40, 255);
    SDL_RenderClear(app.renderer);

    SDL_Color color = {10, 10, 10, 255};

    struct Scene_Position scene_position = {0, 19};
    struct Position position = {0, 0};
    for (int x = -1; x <= SCENE_WIDTH; x++)
    {
        scene_position.x = x;
        position = get_position(&scene_position);
        draw_block(app, position, color);
    }

    for (int y = 0; y < SCENE_HEIGHT; y++)
    {
        scene_position.y = y;

        scene_position.x = -1;
        position = get_position(&scene_position);
        draw_block(app, position, color);

        scene_position.x = SCENE_WIDTH;
        position = get_position(&scene_position);
        draw_block(app, position, color);
    }

    int config[4][4] = {{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    SDL_Color color2 = {255, 0, 0, 255};
    struct Scene_Position piece_scene_position = {5, 5};
    struct Piece piece = {NULL, 't', 0, NULL, NULL, NULL};
    memcpy(piece.configuration, config, sizeof (config));
    piece.color = &color2;
    piece.scene_position = &piece_scene_position;


    draw_piece(app, &piece);
}
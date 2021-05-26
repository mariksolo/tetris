#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "gameplay/Piece.h"
#include <stdio.h>

int main()
{
    struct App app = init_SDL();

    int init_next_action = -1;
    int init_new_piece_needed = 0;
    int init_fall_needed = 0;

    int *next_action = &init_next_action;
    int *new_piece_needed = &init_new_piece_needed;
    int *fall_needed = &init_fall_needed;

    SDL_Color color2 = {255, 0, 0, 255};
    SDL_Color empty_color = {0, 0, 0, 0};
    SDL_Color dead_blocks[20][10] = {{NULL}};
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            dead_blocks[row][col] = empty_color;
        }
    }

    for (int col = 0; col < 10; col++)
    {
        dead_blocks[19][col] = color2;
    }

    for (int col = 0; col < 10; col++)
    {
        dead_blocks[18][col] = color2;
    }

    // dead_blocks[5][5] = color2;
    struct Scene_Position piece_scene_position = {5, 5};

    int config[4][4] = {{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    struct Piece piece = {NULL, 't', 0, NULL, NULL, NULL};
    memcpy(piece.configuration, config, sizeof(config));
    piece.color = &color2;
    piece.scene_position = &piece_scene_position;

    int fall_time_counter = 0;

    while (1)
    {
        read_input(next_action);
        if (fall_time_counter == 30)
        {
            *fall_needed = 1;
            fall_time_counter = 0;
        }
        else
        {
            *fall_needed = 0;
        }
        draw_scene(app, next_action, new_piece_needed, fall_needed, dead_blocks, &piece);
        render_scene(app);

        SDL_Delay(50);
        fall_time_counter++;
    }
    return 0;
}
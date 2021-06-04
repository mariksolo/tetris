#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "gameplay/Piece.h"
#include <stdio.h>
#include "gameplay/piece_configs.h"
#include "gameplay/get_random_piece.h"
#include "gameplay/get_config.h"

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

    struct Scene_Position piece_scene_position = {0, 4};

    int config[4][4] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};
    int dropped[7];
    struct Piece piece = {'s', 0, NULL, NULL, NULL};
    // memcpy(piece.configuration, config, sizeof(config));
    // piece.color = &color2;
    // piece.scene_position = &piece_scene_position;
    
    // get_config(&piece, 'i', 0);
    piece.color = &color2;
    piece.scene_position = &piece_scene_position;
    get_random_piece(&piece, dropped);

    int fall_time_counter = 0;
    int action_timer = 0;

    while (1)
    {
        
        if (action_timer > 2)
        {
            read_input(next_action);
        }

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
        if (*next_action != -1)
        {
            *next_action = -1;
            action_timer = 0;
        }
        if (*new_piece_needed == 1)
        {
            // piece.type = 'q';
            // piece.config_id = 0;
            // memcpy(piece.configuration, config, sizeof(config));
            
            *new_piece_needed = 0;
            // free(piece.color);
            // free(piece.scene_position);
            get_random_piece(&piece, dropped);
            piece.scene_position->x = 3;
            piece.scene_position->y = 0;
        }
        action_timer++;

        SDL_Delay(50);
        fall_time_counter++;
        printf("y: %d\n", piece.scene_position->y);
        printf("x: %d\n", piece.scene_position->x);
        printf("type: %d\n", piece.type);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d, ", piece.configuration[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
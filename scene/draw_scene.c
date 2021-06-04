#include "../common.h"
#include "../structs.h"
#include "../draw.h"
#include "position.h"
#include "../gameplay/Piece.h"
#include "../gameplay/draw_piece.h"
#include "../gameplay/process_state.h"
#include "../gameplay/check_movement.h"
#include "../gameplay/draw_dead_blocks.h"
#include "../gameplay/rotate_piece.h"

void draw_scene(struct App app, int *next_action, int *new_piece_needed, int *fall_needed, SDL_Color dead_blocks[][10], struct Piece *falling_piece)
{
    
    SDL_SetRenderDrawColor(app.renderer, 40, 40, 40, 255);
    SDL_RenderClear(app.renderer);

    SDL_Color color = {10, 10, 10, 255};

    struct Scene_Position scene_position = {0, 20};
    struct Position position = {0, 0};
    for (int x = -1; x <= SCENE_WIDTH; x++)
    {
        scene_position.x = x;
        position = get_position(&scene_position);
        draw_block(app, position, color);
    }

    for (int y = 0; y <= SCENE_HEIGHT; y++)
    {
        scene_position.y = y;

        scene_position.x = -1;
        position = get_position(&scene_position);
        draw_block(app, position, color);

        scene_position.x = SCENE_WIDTH;
        position = get_position(&scene_position);
        draw_block(app, position, color);
    }

    if (*fall_needed)
    {
        falling_piece->scene_position->y = falling_piece->scene_position->y + 1;
    }

    struct Scene_Position proposed_scene_position = {falling_piece->scene_position->x, falling_piece->scene_position->y};
    struct Scene_Position old_scene_position = {falling_piece->scene_position->x, falling_piece->scene_position->y};
    int old_config[4][4];
    memcpy(old_config, falling_piece->configuration, sizeof (old_config));

    if (*next_action == 0)
    {
        proposed_scene_position.x = proposed_scene_position.x - 1;
    }
    else if (*next_action == 1)
    {
        proposed_scene_position.x = proposed_scene_position.x + 1;
    }
    else if (*next_action == 2)
    {
        proposed_scene_position.y = proposed_scene_position.y + 1;
    } else if (*next_action == 3) {
        rotate_piece(falling_piece);
    }
    
    memcpy(falling_piece->scene_position, &proposed_scene_position, sizeof(&proposed_scene_position));
    // memcpy(&proposed_falling_piece.scene_position, &proposed_scene_position, sizeof(proposed_scene_position));

    int points = process_state(dead_blocks);
    draw_dead_blocks(app, dead_blocks);

    if (falling_piece->type == 'e') {
        return;
    }
    int move_result = check_movement(dead_blocks, falling_piece);
    // int move_result = check_movement(dead_blocks, &proposed_falling_piece);

    // draw_piece(app, falling_piece);
    // draw_piece(app, &proposed_falling_piece);
    printf("move_result: %d\n", move_result);
    if (move_result == 1)
    {
        // draw_piece(app, &proposed_falling_piece);
        draw_piece(app, falling_piece);
    }
    else
    {
        // falling_piece->scene_position->y = falling_piece->scene_position->y - 1;
        printf("!move_result\n");
        // falling_piece->scene_position = &old_scene_position;
        memcpy(falling_piece->scene_position, &old_scene_position, sizeof(&old_scene_position));
        memcpy(falling_piece->configuration, old_config, sizeof(old_config));
        move_result = check_movement(dead_blocks, falling_piece);
        if (move_result == 1)
        {
            draw_piece(app, falling_piece);
        }
        else
        {
            printf("!move_result2\n");
            // Set falling_piece to dead_blocks
            falling_piece->scene_position->y = falling_piece->scene_position->y - 1;
            for (int row = falling_piece->scene_position->y; row < falling_piece->scene_position->y + 4; row++)
            {
                for (int col = falling_piece->scene_position->x; col < falling_piece->scene_position->x + 4; col++)
                {   
                    if (falling_piece->configuration[row - falling_piece->scene_position->y][col - falling_piece->scene_position->x])
                        dead_blocks[row][col] = *falling_piece->color;
                }
                *new_piece_needed = 1;
            }
            draw_piece(app, falling_piece);
            falling_piece->type = 'e';
        }
    }

    // check_movement returns -1 if any overlap, determine whether fall overlap or movement overlap by running it without action. If it still doesn't
    // work after a second run through check_movement -> add falling_piece to dead_blocks
}
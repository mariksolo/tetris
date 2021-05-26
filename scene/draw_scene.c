#include "../common.h"
#include "../structs.h"
#include "../draw.h"
#include "position.h"
#include "../gameplay/Piece.h"
#include "../gameplay/draw_piece.h"
#include "../gameplay/process_state.h"

void draw_scene(struct App app, int *next_action, int *new_piece_needed, int *fall_needed, SDL_Color dead_blocks[][10], struct Piece *falling_piece)
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
    
    if (*fall_needed) {
        falling_piece->scene_position->y = falling_piece->scene_position->y + 1;
    }

    struct Scene_Position proposed_scene_position = { falling_piece->scene_position->x, falling_piece->scene_position->y};
    
    if (*next_action == 97) {
        proposed_scene_position.x = proposed_scene_position.x - 1;
    } else if (*next_action == 100) {
        proposed_scene_position.x = proposed_scene_position.x + 1;
    } else if (*next_action == 115) {
        proposed_scene_position.y = proposed_scene_position.y + 1;
    }
    // draw_piece(app, falling_piece);

    int points = process_state(dead_blocks, falling_piece);
    printf("points: %d\n", points);


    // Looks at fall flag pointer passed in to decide downward movement.
    // (Looks at input pointer passed into it. Gets new, proposed, falling (if necessary) piece.)
        // Nevermind
    // passes 2d array of dead blocks and into process_state, gets output of points and new 2d array.
    // Passes new 2d array and proposed falling piece into process_piece, if -1 then repeats step with only fall.
        // -1 = overlap to side -> switch to just fall, no side-to-side or rotation input
        // 0 = overlap to bottom -> don't move, modify dead board to include this piece. Set output piece pointer asking for a new piece
        // 1 = everything is fine -> draw as is

}
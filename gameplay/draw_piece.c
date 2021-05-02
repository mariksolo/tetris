#include "Piece.h"
#include "../common.h"
#include "../draw.h"
#include "../scene/position.h"
#include <stdio.h>

void draw_piece(struct App app, struct Piece *piece)
{
    int scene[20][10] = {{0}};
    struct Scene_Position scene_position = {0, 0};
    struct Position position = {0, 0};
    int row;
    int col;

    for (int i = 0; i < 4; i++)
    {
        row = piece->scene_position->y + i;
        for (int j = 0; j < 4; j++)
        {
            col = piece->scene_position->x + j;
            
            if (piece->configuration[i][j])
            {
                scene_position.x = col;
                scene_position.y = row;
                position = get_position(&scene_position);
                draw_block(app, position, *piece->color);
            }
        }



    }
}
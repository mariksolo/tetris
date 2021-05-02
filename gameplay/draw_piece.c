#include "Piece.h"
#include "../common.h"
#include "../draw.h"
#include "../scene/position.h"
#include <stdio.h>

void draw_piece(struct App app, struct Piece *piece)
{
    // printf("hello world");
    int scene[20][10] = {{0}};
    struct Scene_Position scene_position = {0, 0};
    // struct Scene_Position scene_position;
    struct Position position = {0, 0};
    int row;
    int col;
    // SDL_Color color = *piece->color;
    // scene_position = *piece->scene_position;
    for (int i = 0; i < 4; i++)
    {
        row = piece->scene_position->y + i;
        for (int j = 0; j < 4; j++)
        {
            col = piece->scene_position->x + j;
            printf("%d, %d\n", row, col);
            if (*(*(piece->configuration + i) + j))
            {
                scene_position.x = col;
                scene_position.y = row;
                position = get_position(&scene_position);
                // printf("position: ")
                draw_block(app, position, *piece->color);
            }
        }



    }
}
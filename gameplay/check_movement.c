#include "../common.h"
#include "Piece.h"

int check_movement(SDL_Color dead_blocks[][10], struct Piece *falling_piece)
{

    printf("falling_piece->scene_position->y: %d\n", falling_piece->scene_position->y);

    for (int row = falling_piece->scene_position->y; row < falling_piece->scene_position->y + 4; row++)
    {
        for (int col = falling_piece->scene_position->x; col < falling_piece->scene_position->x + 4; col++)
        {

            if (falling_piece->configuration[row - falling_piece->scene_position->y][col - falling_piece->scene_position->x]) {
                if (dead_blocks[row][col].a) {
                    return -1;
                }

                if (row < 0 || row > 19 || col < 0 || col > 9) {
                    return -1;
                }
            }
           
        }
    }
    return 1;
}
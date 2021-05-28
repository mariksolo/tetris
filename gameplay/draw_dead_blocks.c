#include "../common.h"
#include "../scene/position.h"
#include "../structs.h"

void draw_dead_blocks(struct App app, SDL_Color dead_blocks[][10])
{
    struct Position position = {0, 0};
    struct Scene_Position scene_position = {0, 0};
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (dead_blocks[row][col].a)
            {
                scene_position.x = col;
                scene_position.y = row;
                position = get_position(&scene_position);
                draw_block(app, position, dead_blocks[row][col]);
            }
        }
    }
}
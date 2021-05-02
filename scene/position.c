#include "../structs.h"
#include "../common.h"

struct Position get_position(struct Scene_Position *scene_position) {
    int x = (SCREEN_WIDTH / 2.0 - 5 * BLOCK_SIZE) + scene_position->x * BLOCK_SIZE;
    int y = (SCREEN_HEIGHT * 0.08) + scene_position->y * BLOCK_SIZE;
    struct Position position = {x, y};
    return position;


}
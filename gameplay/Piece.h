#ifndef PIECE
#define PIECE
#include "../structs.h"
#include "SDL2/SDL.h"

struct Piece {
    char type;
    int config_id;
    int configuration[4][4];
    struct SDL_Color *color;
    struct Scene_Position *scene_position;
};

#endif
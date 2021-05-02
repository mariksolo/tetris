#ifndef PIECE
#define PIECE
#include "../structs.h"
#include "SDL2/SDL.h"

struct Piece {
    void *rotate;
    char type;
    int config_id;
    int **configuration;
    struct SDL_Color *color;
    struct Scene_Position *scene_position;
};

#endif
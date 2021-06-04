#include "Piece.h"
#include "piece_configs.h"
#include <stdlib.h>
#include "get_config.h"

void get_random_piece(struct Piece *piece, int dropped[7]) {
    srand(time(NULL));
    double random_fraction = rand() * 1.0 / RAND_MAX;
    int random_piece = (int) (random_fraction * 6);
    // SDL_Color red = {255, 0, 0, 255};
    // struct Scene_Position piece_scene_position = {3, 0};
    // SDL_Color *red_p = malloc(sizeof(red));
    // struct Scene_Position *piece_scene_position_p = malloc(sizeof(piece_scene_position));
    // red_p = &red;
    // piece_scene_position_p = &piece_scene_position;
    
    switch (random_piece) {
        case 0:
            get_config(piece, 's', 0);
            piece->type = 's';
            break;
        case 1:
            get_config(piece, 'z', 0);
            piece->type = 'z';
            break;
        case 2:
            get_config(piece, 'l', 0);
            piece->type = 'l';
            break;
        case 3:
            get_config(piece, 'j', 0);
            piece->type = 'j';
            break;
        case 4:
            get_config(piece, 'q', 0);
            piece->type = 'q';
            break;
        case 5:
            get_config(piece, 'i', 0);
            piece->type = 'i';
            break;
        case 6:
            get_config(piece, 't', 0);
            piece->type = 't';
            break;
        
    }
    piece->config_id = 0;
    
    // piece->scene_position->x = 3;
    // piece->scene_position->y = 0;
    // piece->color = red_p;
    // piece->scene_position = piece_scene_position_p;
    
}
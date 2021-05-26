#include "common.h"

void read_input(int *next_action)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case 97: // a
                *next_action = 0;
                break;
            case 100: // d
                *next_action = 1;
                break;
            case 115: // s
                *next_action = 2;
                break;
            case 119: // w
                *next_action = 3;
                break;
            }
            break;

        default:
            // printf("switch\n");
            break;
        }
    }
}
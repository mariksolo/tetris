#ifndef STRUCTS
#define STRUCTS
#include "SDL2/SDL.h"

struct App
{
    SDL_Renderer *renderer;
    SDL_Window *window;
};

struct Position
{
    int x;
    int y;
};

struct Scene_Position
{
    int x;
    int y;
};

struct Color
{
    int r;
    int g;
    int b;
};

#endif
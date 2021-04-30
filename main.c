#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include <stdio.h>

int main()
{
    struct App app = init_SDL();

    while (1)
    {
        initialize_scene(app);
        render_scene(app);
        read_input();
        SDL_Delay(16);
    }
    return 0;
}
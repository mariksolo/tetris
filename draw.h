#ifndef DRAW
#define DRAW
void initialize_scene(struct App app);
void render_scene(struct App app);
void draw_block(struct App app, struct Position position, SDL_Color color);

#endif
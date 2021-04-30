#include "common.h"
#include "structs.h"
#include "scene/draw_scene.h"

void draw_block(struct App app, struct Position position, SDL_Color color);

void initialize_scene(struct App app)
{
	// SDL_SetRenderDrawColor(app.renderer, 40, 40, 40, 255);
	// SDL_RenderClear(app.renderer);
	// struct Position position = {50, 50};
	// SDL_Color color = {255, 0, 255, 255};
	// draw_block(app, position, color);
	draw_scene(app);
}

void render_scene(struct App app)
{
	SDL_RenderPresent(app.renderer);
}

void draw_block(struct App app, struct Position position, SDL_Color color)
{
	SDL_Rect rectangle = {position.x, position.y, BLOCK_SIZE, BLOCK_SIZE};
	SDL_SetRenderDrawColor(app.renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(app.renderer, &rectangle);
}
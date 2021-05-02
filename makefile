COMPILER=gcc
CFLAGS = -g -Wall `pkg-config --cflags --libs sdl2`

tetris:
	@$(COMPILER) -c $(CFLAGS) init.c -Iinclude/ -o bin/init.o
	@$(COMPILER) -c $(CFLAGS) draw.c -Iinclude/ -o bin/draw.o
	@$(COMPILER) -c $(CFLAGS) input.c -Iinclude/ -o bin/input.o
	@$(COMPILER) -c $(CFLAGS) scene/draw_scene.c -Iinclude/ -o bin/draw_scene.o
	@$(COMPILER) -c $(CFLAGS) scene/position.c -Iinclude/ -o bin/position.o
	@$(COMPILER) -c $(CFLAGS) gameplay/draw_piece.c -Iinclude/ -o bin/draw_piece.o
	@$(COMPILER) -c $(CFLAGS) main.c -Iinclude/ -o bin/main.o
	@$(COMPILER) $(CFLAGS) bin/init.o bin/draw.o bin/input.o bin/draw_scene.o bin/draw_piece.o bin/position.o bin/main.o -o tetris
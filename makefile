COMPILER=gcc
CFLAGS = -g -Wall `pkg-config --cflags --libs sdl2`

tetris:
	@$(COMPILER) -c $(CFLAGS) init.c -Iinclude/ -o bin/init.o
	@$(COMPILER) -c $(CFLAGS) draw.c -Iinclude/ -o bin/draw.o
	@$(COMPILER) -c $(CFLAGS) input.c -Iinclude/ -o bin/input.o
	@$(COMPILER) -c $(CFLAGS) scene/draw_scene.c -Iinclude/ -o bin/draw_scene.o
	@$(COMPILER) -c $(CFLAGS) scene/position.c -Iinclude/ -o bin/position.o
	@$(COMPILER) -c $(CFLAGS) gameplay/draw_piece.c -Iinclude/ -o bin/draw_piece.o
	@$(COMPILER) -c $(CFLAGS) gameplay/process_state.c -Iinclude/ -o bin/process_state.o
	@$(COMPILER) -c $(CFLAGS) gameplay/check_movement.c -Iinclude/ -o bin/check_movement.o
	@$(COMPILER) -c $(CFLAGS) gameplay/draw_dead_blocks.c -Iinclude/ -o bin/draw_dead_blocks.o
	@$(COMPILER) -c $(CFLAGS) gameplay/rotate_piece.c -Iinclude/ -o bin/rotate_piece.o
	@$(COMPILER) -c $(CFLAGS) gameplay/get_random_piece.c -Iinclude/ -o bin/get_random_piece.o
	@$(COMPILER) -c $(CFLAGS) gameplay/get_config.c -Iinclude/ -o bin/get_config.o
	@$(COMPILER) -c $(CFLAGS) main.c -Iinclude/ -o bin/main.o
	@$(COMPILER) $(CFLAGS) bin/init.o bin/draw.o bin/input.o bin/draw_scene.o bin/draw_piece.o bin/position.o bin/process_state.o bin/check_movement.o bin/draw_dead_blocks.o bin/rotate_piece.o bin/get_random_piece.o bin/get_config.o bin/main.o -o tetris
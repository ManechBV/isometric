#include "raylib.h"

#include "utils.h"
#include "tilemap.h"

#include <stdlib.h>

int	main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	t_tilemap	*tilemap;
	tilemap = ft_create_tilemap("res/spritesheet.png", 32, 32);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		EndDrawing();
	}

	ft_free_tilemap(tilemap);
	CloseWindow();
	return (0);
}

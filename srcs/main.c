#include "raylib.h"
#include "tileset.h"
#include "tilemap.h"

int	main()
{
	InitWindow(1280, 720, "Hello");
	SetTargetFPS(60);

	Texture2D	tileset_texture = LoadTexture("res/spritesheet.png");
	t_tileset	tileset = create_tileset(tileset_texture, 32, 32);

	t_tilemap	tilemap = create_tilemap(&tileset, 32, 32, 0);

	// temp loop to generate random map
	for (int x = 0; x < tilemap.width; x++)
	{
		for (int y = 0; y < tilemap.height; y++)
		{
			tilemap.map[y][x] = GetRandomValue(0, 50);
		}
	}

	bool	running = true;
	while (running)
	{
		//Update game

		
		//Draw game
		BeginDrawing();

		ClearBackground(DARKGRAY);

		//_draw_tileset(tileset);
		draw_tilemap(&tilemap, (Vector2){640, 100});

		EndDrawing();
	
		//Condition to stop the loop
		if (WindowShouldClose())
			running = false;
	}
	tilemap.width = 0;
	
	free_tilemap(&tilemap);
	free_tileset(&tileset);
	
	CloseWindow();
	return (0);
}

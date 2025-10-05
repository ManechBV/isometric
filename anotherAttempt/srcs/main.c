#include "raylib.h"
#include "tileset.h"
#include "tilemap.h"

int	main()
{
	InitWindow(1280, 720, "Hello");
	SetTargetFPS(60);

	Texture2D	tileset_texture = LoadTexture("res/isometric-sandbox-sheet.png");
	t_tileset	tileset = create_tileset(tileset_texture, 32, 32);

	t_tilemap	tilemap = create_tilemap(&tileset, 16, 16, 0);

	bool	running = true;
	while (running)
	{
		//Update game

		
		//Draw game
		BeginDrawing();

		ClearBackground(DARKGRAY);

		//_draw_tileset(tileset);
		//draw_tilemap(&tilemap, (Vector2){10, 10});

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

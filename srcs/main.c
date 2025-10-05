#include "raylib.h"
#include "tileset.h"
#include "tilemap.h"
#include "camera_controller.h"

int	main()
{
	InitWindow(1280, 720, "Hello");
	SetTargetFPS(60);

	Texture2D	tileset_texture = LoadTexture("res/spritesheet.png");
	t_tileset	tileset = create_tileset(tileset_texture, 32, 32);

	t_tilemap	tilemap = create_tilemap(&tileset, 32, 32, 0);

	Camera2D	camera = {0};
	camera.target = (Vector2){640, 300};
	camera.offset = (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2};
	camera.rotation = 0.0f;
	camera.zoom = 2.0f;

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
		move_camera_screen_border(&camera, 20, 4);
		zoom_camera_mouse_wheel(&camera, 0.2);
		
		//Draw game
		BeginDrawing();

		ClearBackground(DARKGRAY);

			BeginMode2D(camera);
				draw_tilemap(&tilemap, (Vector2){640, 100});
			EndMode2D();

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

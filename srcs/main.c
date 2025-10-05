#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"
#include "raylib.h"
#include "tileset.h"
#include "tilemap.h"
#include "camera_controller.h"

int	main(int argc, char **argv)
{
	InitWindow(1280, 720, argv[0]);
	//SetTargetFPS(60);

	char	*spritesheet_path;
	int		arg_tile_w = 32;
	int		arg_tile_h = 32;
	if (argc > 3)
	{
		spritesheet_path = argv[1];
		arg_tile_w = atoi(argv[2]);
		arg_tile_h = atoi(argv[3]);
	}
	else
		spritesheet_path = "res/spritesheet.png";
		
	Texture2D	tileset_texture = LoadTexture(spritesheet_path);
	t_tileset	tileset = create_tileset(tileset_texture, arg_tile_w, arg_tile_h, spritesheet_path);

	t_tilemap	tilemap = create_tilemap(&tileset, 64, 64, 0);

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
			tilemap.map[y][x] = GetRandomValue(0, tileset.size - 1);
		}
	}

	// TEST N SHIT
	char	*tilemap_str = tilemap_to_str(&tilemap);
	printf("tilemap_str:\n|%s|\n", tilemap_str);

	bool	running = true;
	while (running)
	{
		//Update game
		// Update camera
			//move_camera_screen_border(&camera, 20, 4);
			move_camera_middle_mouse(&camera, camera.zoom);
			zoom_camera_mouse_wheel(&camera, 0.1);
		
		//Draw game
		BeginDrawing();

		ClearBackground(DARKGRAY);

			BeginMode2D(camera);
				draw_tilemap(&tilemap, (Vector2){640, 100});
			EndMode2D();

		DrawFPS(10, 10);
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

#include "tilemap.h"
#include <stdlib.h>


t_tilemap	create_tilemap(t_tileset *tileset, int width, int height, int fill)
{
	t_tilemap	tilemap;

	tilemap.map = malloc(sizeof(int*) * (height));
	for (int i = 0; i < height; i++)
		tilemap.map[i] = malloc(sizeof(int) * (width));
	
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
			tilemap.map[y][x] = fill;
	}
	
	tilemap.tileset = tileset;
	tilemap.width = width;
	tilemap.height = height;

	return (tilemap);
}

void	draw_tilemap(t_tilemap *tilemap, Vector2 position)
{
	for (int y = 0; y < tilemap->height; y++)
	{
		for (int x = 0; x < tilemap->width; x++)
		{
			draw_tile(&((tilemap->tileset->tiles)[(tilemap->map)[y][x]]), (Vector2){
				position.x + x * tilemap->tileset->tile_w, 
				position.y + y * tilemap->tileset->tile_h
			}); 
		}
	}
}

void	set_tile(t_tilemap *tilemap, int x, int y, int value)
{
	(tilemap->map)[y][x] = value; 
}

int			get_tile(t_tilemap *tilemap, int x, int y)
{
	return ((tilemap->map)[y][x]);
}

void	free_tilemap(t_tilemap *tilemap)
{
	free(tilemap->map);
}

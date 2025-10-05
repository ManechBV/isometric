#include "tilemap.h"
#include "utils.h"
#include <stdlib.h>


t_tilemap	create_tilemap(t_tileset *tileset, int width, int height, int fill)
{
	t_tilemap	tilemap;

	tilemap.map = malloc(sizeof(int*) * (width));
	for (int i = 0; i < width; i++)
		tilemap.map[i] = malloc(sizeof(int) * (height));
	
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
			tilemap.map[y][x] = fill;
	}
	
	tilemap.tileset = tileset;
	tilemap.width = width;
	tilemap.height = height;

	return (tilemap);
}

void	draw_tilemap(t_tilemap *tilemap, Vector2 position)
{
	for (int x = 0; x < tilemap->width; x++)
	{
		for (int y = 0; y < tilemap->height; y++)
		{
			int	tile_w = tilemap->tileset->tile_w;
			int	tile_h = tilemap->tileset->tile_h;

			Vector2	pos_iso = coord_to_iso((Vector2){x, y}, tile_w, tile_h);

			draw_tile(&((tilemap->tileset->tiles)[(tilemap->map)[y][x]]), (Vector2){
				position.x + pos_iso.x, 
				position.y + pos_iso.y
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
	for (int i = 0; i < tilemap->width; i++)
		free((tilemap->map)[i]);
	free(tilemap->map);
}

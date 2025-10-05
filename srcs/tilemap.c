#include "tilemap.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>


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

char	*tilemap_to_str(t_tilemap *tilemap)
{
	int	size = 0;

	//the first line of the file should be in this format: "WIDTH:HEIGHT\n", example: "64:64\n"
	size += num_len(tilemap->width) + 1 +  num_len(tilemap->width) + 1;

	//the second line of the file should be the path to the spritesheet image that must be placed in res/
	size += strlen(tilemap->tileset->image_name) + 1;	//\n at the end of course

	//the third and last line of the file sould be all the tiles values from top left to bottom right separated by ':'
	for (int x = 0; x < tilemap->width; x++)
	{
		for (int y = 0; y < tilemap->height; y++)
			size += num_len((tilemap->map)[y][x]) + 1;
	}
	size++; // '\0'

	char	*str = malloc(sizeof(char) * size);
	str[0] = '\0';

	//first line
	strcat(str, ft_itoa(tilemap->width));
	strcat(str, ":");
	strcat(str, ft_itoa(tilemap->height));
	strcat(str, "\n");
	
	//second line
	strcat(str, tilemap->tileset->image_name);
	strcat(str, "\n");

	//third line
	for (int x = 0; x < tilemap->width; x++)
	{
		for (int y = 0; y < tilemap->height; y++)
		{
			strcat(str, ft_itoa((tilemap->map)[y][x]));
			strcat(str, ":");
		}
	}

	return (str);
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

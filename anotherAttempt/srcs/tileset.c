#include "tileset.h"
#include <stdlib.h>

t_tile		create_tile(Texture2D texture, float x, float y, float w, float h)
{
	t_tile	tile;
	tile.texture = texture;
	tile.rect = (Rectangle){x, y, w, h};
	return (tile);
}

t_tileset	create_tileset(Texture2D texture, int tile_w, int tile_h)
{
	t_tileset	tileset;

	tileset.size = (texture.width / tile_w) * (texture.height / tile_h);
	tileset.tiles = malloc(sizeof(t_tile) * tileset.size);

	int	x = 0;
	int	y = 0;
	for (int i = 0; i < tileset.size; i++)
	{
		tileset.tiles[i] = create_tile(texture, (float)x, (float)y, (float)tile_w, (float)tile_h);
		x += tile_w;
		if (x >= texture.width)
		{
			x = 0;
			y += tile_h;
			if (y >= texture.height)
				y = 0;
		}
	}
	tileset.tile_w = tile_w;
	tileset.tile_h = tile_h;

	return (tileset);
}

void	free_tileset(t_tileset *tileset)
{
	if (tileset->tiles)
		free(tileset->tiles);
	tileset->tiles = NULL;
	tileset->size = 0;
}

void	draw_tile(t_tile *tile, Vector2 position)
{
	DrawTextureRec(tile->texture, tile->rect, position, RAYWHITE);
}

void	_draw_tileset(t_tileset tileset)
{
	for (int i = 0; i < tileset.size; i++)	
	{
		DrawRectangleLinesEx(tileset.tiles[i].rect, 1.0, RED);
		DrawTextureRec(
			tileset.tiles[i].texture,
			tileset.tiles[i].rect,
			(Vector2){tileset.tiles[i].rect.x, tileset.tiles[i].rect.y},
			RAYWHITE
		);
	}
}

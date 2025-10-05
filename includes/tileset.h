#ifndef TILESET_H
# define TILESET_H

# include "raylib.h"

typedef struct	s_tile
{
	Texture2D	texture;
	Rectangle	rect;
} t_tile;

typedef struct	s_tileset
{
	t_tile	*tiles;
	int		size;
	int		tile_w;
	int		tile_h;
} t_tileset;

t_tile		create_tile(Texture2D texture, float x, float y, float w, float h);
t_tileset	create_tileset(Texture2D texture, int tile_w, int tile_h);
void		_draw_tileset(t_tileset tileset);
void		free_tileset(t_tileset *tileset);
void		draw_tile(t_tile *tile, Vector2 position);

#endif

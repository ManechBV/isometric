#ifndef TILEMAP_H
# define TILEMAP_H

# include "tileset.h"
# include "raylib.h"

typedef struct	s_tilemap
{
	t_tileset	*tileset;
	int			**map;
	int			width;
	int			height;
} t_tilemap;

t_tilemap	create_tilemap(t_tileset *tileset, int width, int height, int fill);
void		set_tile(t_tilemap *tilemap, int x, int y, int value);
int			get_tile(t_tilemap *tilemap, int x, int y);
void		free_tilemap(t_tilemap *tilemap);
void		draw_tilemap(t_tilemap *tilemap, Vector2 position);

#endif

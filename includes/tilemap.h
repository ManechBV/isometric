#ifndef TILEMAP_H
# define TILEMAP_H

# include "raylib.h" 

typedef struct s_tilemap
{
	Texture2D	sprite_sheet;
	Rectangle	draw_rect;
} t_tilemap;

//tilemap.c
t_tilemap	*ft_create_tilemap(char *filename, float tile_size_x, float tile_size_y);

void	ft_free_tilemap(t_tilemap *tilemap);

#endif

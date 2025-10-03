#include "tilemap.h"

#include <stdlib.h>

t_tilemap	*ft_create_tilemap(char *filename, float tile_size_x, float tile_size_y)
{
	t_tilemap	*new_tilemap;

	new_tilemap = malloc(sizeof(t_tilemap));	
	if (!new_tilemap)
		return (NULL);

	new_tilemap->sprite_sheet = LoadTexture(filename);

	new_tilemap->draw_rect.x = 0.0;
	new_tilemap->draw_rect.y = 0.0;
	new_tilemap->draw_rect.width = tile_size_x;
	new_tilemap->draw_rect.height = tile_size_y;

	return (new_tilemap);
}

void	ft_free_tilemap(t_tilemap *tilemap)
{
	UnloadTexture(tilemap->sprite_sheet);
	free(tilemap);
}

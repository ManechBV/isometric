#include "utils.h"

Vector2	coord_to_iso(Vector2 vec, int tile_w, int tile_h)
{
	Vector2	pos_iso = {0};
	//pos_iso.x = vec.x * (tile_w * 0.5) + vec.y * (-0.5 * tile_w);
	//pos_iso.y = vec.x * (0.25 * tile_h) + vec.y * (0.25 * tile_h);
	//pos_iso.x -= tile_w / 2;
	tile_h = tile_w;
	pos_iso.x = vec.x * (tile_w * 0.5) + vec.y * (-0.5 * tile_w);
	pos_iso.y = vec.x * (0.25 * tile_h) + vec.y * (0.25 * tile_h);
	pos_iso.x -= tile_w / 2;
	return (pos_iso);
}

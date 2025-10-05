#ifndef UTILS_H
# define UTILS_H

# include "raylib.h"

Vector2	coord_to_iso(Vector2 vec, int tile_w, int tile_h);
bool	file_already_exist(char *path);
int		num_len(int a);
char	*ft_itoa(int num);
int		ft_strlen(char *str);

#endif

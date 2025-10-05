#include <stdlib.h>
#include <unistd.h>
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

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	num_len(int a)
{
	if (a == 0)
		return (0);
	if (a <= 9)
		return (1);
	else
		return (1 + num_len(a / 10));
}

char	*ft_itoa(int num)
{
	if (num < 0)
		return (NULL);
	
	char	*str = malloc(sizeof(char) * (num_len(num) + 1));
	int		i = num_len(num);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}
	return (str);
}

bool	file_already_exist(char *path)
{
	if (access(path, F_OK) == 0)
		return (true);
	return (false);
}

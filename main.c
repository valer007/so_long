#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include "stdio.h"
#include "./libft/libft.h"

int	main(void)
{
	char 	*map;

	int fd = open("map.ber", O_RDONLY);
	map = get_next_line(fd);
	printf("%s", map);
	while (map && *map)
	{
		map = get_next_line(fd);
		printf("%s", map);
	}
	return (0);
}

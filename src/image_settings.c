#include "so_long.h"

t_image_path	image_path()
{
	t_image_path path;

	path.mlx = mlx_init();
    path.win = mlx_new_window(path.mlx, 1500, 400, "so_long");
	path.img_width = 0;
	path.img_height = 0;
    path.shenq_img = mlx_xpm_file_to_image(path.mlx, "assets/shenq.xpm", &path.img_width, &path.img_height);
	path.lights = mlx_xpm_file_to_image(path.mlx, "assets/traffic_lights.xpm", &path.img_width, &path.img_height);
	path.img = mlx_xpm_file_to_image(path.mlx, "assets/asphalt.xpm", &path.img_width, &path.img_height);
	path.player = mlx_xpm_file_to_image(path.mlx, "assets/car_right.xpm", &path.img_width, &path.img_height);
	path.girl = mlx_xpm_file_to_image(path.mlx, "assets/girl.xpm", &path.img_width, &path.img_height);
	path.home = mlx_xpm_file_to_image(path.mlx, "assets/home.xpm", &path.img_width, &path.img_height);

return (path);
}

void	checking_map(char **map, int map_lines)
{
	int				i;
	int				j;
	t_image_path	path;

	path = image_path();
	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[0][j] == '1' && map[map_lines][j] == '1')
		{
			mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, 0 * path.img_height);
			mlx_put_image_to_window(path.mlx, path.win, path.shenq_img, j * path.img_width, 0 * path.img_height);
			
			mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, map_lines * path.img_height);
			mlx_put_image_to_window(path.mlx, path.win, path.shenq_img, j * path.img_width, map_lines * path.img_height);
		}
		j++;
	}
}

void checking_map1(char **map)
{
	int i;
	int j;
	int size;
	t_image_path path;

	path = image_path();
	size = ft_strlen(map[0]) - 2;
	i = 0;
	while (map[i++])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][0] == '1')
			{
				mlx_put_image_to_window(path.mlx, path.win, path.img, 0 * path.img_width, i * path.img_height);
				mlx_put_image_to_window(path.mlx, path.win, path.shenq_img, 0 * path.img_width, i * path.img_height);
			}
			if (map[i][size] == '1')
			{
				mlx_put_image_to_window(path.mlx, path.win, path.img, size * path.img_width, i * path.img_height);
				mlx_put_image_to_window(path.mlx, path.win, path.shenq_img, size * path.img_width, i * path.img_height);
			}
		}
	}
}

void  checking_map2(char **map, int map_lines)
{
	int				i;
	int				j;
	t_image_path	path;
	int				size;

	size = ft_strlen(map[0]) - 2;
	path = image_path();
	i = 1;
	while (i < map_lines)
	{
		j = 1;
		while (j < size)
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, i * path.img_height);
				mlx_put_image_to_window(path.mlx, path.win, path.lights, j * path.img_width, i * path.img_height);
			}
			j++;
		}
		i++;
	}
}

void checking_map3(char **map)
{
	int				i;
	int				j;
	t_image_path	path;

	i = 0;
	while (map[i++])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, i * path.img_height);
			if (map[i][j] == 'P') {
				mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, i * path.img_height);
				mlx_put_image_to_window(path.mlx, path.win, path.player, j * path.img_width, i * path.img_height);
			}
			if (map[i][j] == 'C') {
				mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, i * path.img_height);
				mlx_put_image_to_window(path.mlx, path.win, path.girl, j * path.img_width, i * path.img_height);
			}
			if (map[i][j] == 'E') {
				mlx_put_image_to_window(path.mlx, path.win, path.img, j * path.img_width, i * path.img_height);
				mlx_put_image_to_window(path.mlx, path.win, path.home, j * path.img_width, i * path.img_height);
			}
		}
	}
}

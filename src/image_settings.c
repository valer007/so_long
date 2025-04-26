/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:49:40 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/26 18:38:41 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_drawctx *test)
{
	free(test);
	exit(0);
}

int	start_game(char **argv, char **map)
{
	t_drawctx	*test;
	int			map_lines;

	test = malloc(sizeof(t_drawctx));
	test->frame_count = 0;
	test->move_count = 0;
	test->dir = 1;
	map_lines = count_lines(argv[1]) - 1;
	test->mlx = mlx_init();
	test->win = mlx_new_window(test->mlx, 1500, 400, "so_long");
	test->map = map;
	load_images(&(test->img), test->mlx);
	draw_top_bottom(test->map, map_lines, test->img, test->win);
	draw_left_right(test->map, test->img, test->win);
	draw_inner_walls(test->map, map_lines, test->img, test->win);
	draw_elements(test, 0);
	mlx_hook(test->win, 2, 1L << 0, handle_key, test);
	mlx_hook(test->win, 17, 0, close_window, test);
	mlx_loop(test->mlx);
	free_map(map);
	return (0);
}

void	load_images(t_img *img, void *mlx)
{
	img->img_width = 0;
	img->img_height = 0;
	img->shenq_img = mlx_xpm_file_to_image(mlx, "assets/shenq.xpm",
			&img->img_width, &img->img_height);
	img->lights = mlx_xpm_file_to_image(mlx, "assets/traffic_lights.xpm",
			&img->img_width, &img->img_height);
	img->img = mlx_xpm_file_to_image(mlx, "assets/asphalt.xpm", &img->img_width,
			&img->img_height);
	img->player_right = mlx_xpm_file_to_image(mlx, "assets/car_right.xpm",
			&img->img_width, &img->img_height);
	img->player_left = mlx_xpm_file_to_image(mlx, "assets/car_left.xpm",
			&img->img_width, &img->img_height);
	img->player_down = mlx_xpm_file_to_image(mlx, "assets/car_down.xpm",
			&img->img_width, &img->img_height);
	img->player_up = mlx_xpm_file_to_image(mlx, "assets/car_up.xpm",
			&img->img_width, &img->img_height);
	img->girl = mlx_xpm_file_to_image(mlx, "assets/girl.xpm", &img->img_width,
			&img->img_height);
	img->home = mlx_xpm_file_to_image(mlx, "assets/home.xpm", &img->img_width,
			&img->img_height);
	img->enemy_left = mlx_xpm_file_to_image(mlx, "assets/enemy_left.xpm",
			&img->img_width, &img->img_height);
	img->enemy_right = mlx_xpm_file_to_image(mlx, "assets/enemy_right.xpm",
			&img->img_width, &img->img_height);
}

void	draw_top_bottom(char **map, int map_lines, t_img img, void *win)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] == '1' && map[map_lines][j] == '1')
		{
			mlx_put_image_to_window(img.mlx, win, img.img, j * img.img_width, 0
				* img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img, j
				* img.img_width, 0 * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.img, j * img.img_width,
				map_lines * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img, j
				* img.img_width, map_lines * img.img_height);
		}
		j++;
	}
}

void	draw_left_right(char **map, t_img img, void *win)
{
	int	i;
	int	size;

	size = ft_strlen(map[0]) - 2;
	i = 0;
	while (map[i])
	{
		if (map[i][0] == '1')
		{
			mlx_put_image_to_window(img.mlx, win, img.img, 0 * img.img_width, i
				* img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img, 0
				* img.img_width, i * img.img_height);
		}
		if (map[i][size] == '1')
		{
			mlx_put_image_to_window(img.mlx, win, img.img, size * img.img_width,
				i * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img, size
				* img.img_width, i * img.img_height);
		}
		i++;
	}
}

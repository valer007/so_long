/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:49:40 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/21 13:34:50 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(0);
}

int	start_game(char **argv, char **map)
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		map_lines;

	map_lines = count_lines(argv[1]) - 1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 400, "so_long");
	load_images(&img, mlx);
	draw_top_bottom(map, map_lines, img, win);
	draw_left_right(map, img, win);
	draw_inner_walls(map, map_lines, img, win);
	draw_elements(map, img, win);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	free_map(map);
	return (0);
}

void	load_images(t_img *img, void *mlx)
{
	img->img_width = 0;
	img->img_height = 0;
	img->shenq_img = mlx_xpm_file_to_image(mlx,
			"assets/shenq.xpm", &img->img_width, &img->img_height);
	img->lights = mlx_xpm_file_to_image(mlx,
			"assets/traffic_lights.xpm", &img->img_width, &img->img_height);
	img->img = mlx_xpm_file_to_image(mlx,
			"assets/asphalt.xpm", &img->img_width, &img->img_height);
	img->player = mlx_xpm_file_to_image(mlx,
			"assets/car_right.xpm", &img->img_width, &img->img_height);
	img->girl = mlx_xpm_file_to_image(mlx,
			"assets/girl.xpm", &img->img_width, &img->img_height);
	img->home = mlx_xpm_file_to_image(mlx,
			"assets/home.xpm", &img->img_width, &img->img_height);
}

void	draw_top_bottom(char **map, int map_lines, t_img img, void *win)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] == '1' && map[map_lines][j] == '1')
		{
			mlx_put_image_to_window(img.mlx, win, img.img,
				j * img.img_width, 0 * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img,
				j * img.img_width, 0 * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.img,
				j * img.img_width, map_lines * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img,
				j * img.img_width, map_lines * img.img_height);
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
			mlx_put_image_to_window(img.mlx, win, img.img,
				0 * img.img_width, i * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img,
				0 * img.img_width, i * img.img_height);
		}
		if (map[i][size] == '1')
		{
			mlx_put_image_to_window(img.mlx, win, img.img,
				size * img.img_width, i * img.img_height);
			mlx_put_image_to_window(img.mlx, win, img.shenq_img,
				size * img.img_width, i * img.img_height);
		}
		i++;
	}
}

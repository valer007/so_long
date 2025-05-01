/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:49:40 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/29 22:01:58 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_drawctx *test)
{
	free_mlx(test);
	return (0);
}

int	start_game(char **argv, char **map)
{
	t_drawctx	*test;
	int			map_lines;

	test = malloc(sizeof(t_drawctx));
	test->frame_count = 0;
	test->move_count = 0;
	test->dir = 1;
	initialize(test);
	test->map = map;
	set_enemy_position(test, 1);
	map_lines = count_lines(argv[1]) - 1;
	test->mlx = mlx_init();
	test->win = mlx_new_window(test->mlx, ft_strlen(map[0]) * WIDTH, (map_lines
				+ 1) * HEIGHT, "so_long");
	load_images(test);
	draw_top_bottom(test, map_lines);
	draw_left_right(test);
	draw_inner_walls(test, map_lines);
	draw_elements(test, 0);
	mlx_hook(test->win, 2, 1L << 0, handle_key, test);
	mlx_hook(test->win, 17, 0, close_window, test);
	mlx_loop(test->mlx);
	return (0);
}

void	load_images(t_drawctx *ctx)
{
	ctx->img.img_width = 0;
	ctx->img.img_height = 0;
	ctx->img.grass = mlx_xpm_file_to_image(ctx->mlx, "assets/grass.xpm",
			&ctx->img.img_width, &ctx->img.img_height);
	ctx->img.lights = mlx_xpm_file_to_image(ctx->mlx, "assets/lights.xpm",
			&ctx->img.img_width, &ctx->img.img_height);
	ctx->img.img = mlx_xpm_file_to_image(ctx->mlx, "assets/asphalt.xpm",
			&ctx->img.img_width, &ctx->img.img_height);
	ctx->img.player_right = mlx_xpm_file_to_image(ctx->mlx,
			"assets/car_right.xpm", &ctx->img.img_width, &ctx->img.img_height);
	ctx->img.player_left = mlx_xpm_file_to_image(ctx->mlx,
			"assets/car_left.xpm", &ctx->img.img_width, &ctx->img.img_height);
	ctx->img.player_down = mlx_xpm_file_to_image(ctx->mlx,
			"assets/car_down.xpm", &ctx->img.img_width, &ctx->img.img_height);
	ctx->img.player_up = mlx_xpm_file_to_image(ctx->mlx, "assets/car_up.xpm",
			&ctx->img.img_width, &ctx->img.img_height);
	ctx->img.girl = mlx_xpm_file_to_image(ctx->mlx, "assets/girls.xpm",
			&ctx->img.img_width, &ctx->img.img_height);
	ctx->img.home = mlx_xpm_file_to_image(ctx->mlx, "assets/home.xpm",
			&ctx->img.img_width, &ctx->img.img_height);
	ctx->img.enemy_left = mlx_xpm_file_to_image(ctx->mlx,
			"assets/enemy_left.xpm", &ctx->img.img_width, &ctx->img.img_height);
	ctx->img.enemy_right = mlx_xpm_file_to_image(ctx->mlx,
			"assets/enemy_right.xpm", &ctx->img.img_width,
			&ctx->img.img_height);
}

void	draw_top_bottom(t_drawctx *ctx, int map_lines)
{
	int	j;

	j = 0;
	while (ctx->map[0][j])
	{
		if (ctx->map[0][j] == '1' && ctx->map[map_lines][j] == '1')
		{
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, j
				* ctx->img.img_width, 0 * ctx->img.img_height);
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.grass, j
				* ctx->img.img_width, 0 * ctx->img.img_height);
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, j
				* ctx->img.img_width, map_lines * ctx->img.img_height);
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.grass, j
				* ctx->img.img_width, map_lines * ctx->img.img_height);
		}
		j++;
	}
}

void	draw_left_right(t_drawctx *ctx)
{
	int	i;
	int	size;

	size = ft_strlen(ctx->map[0]) - 2;
	i = 0;
	while (ctx->map[i])
	{
		if (ctx->map[i][0] == '1')
		{
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, 0
				* ctx->img.img_width, i * ctx->img.img_height);
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.grass, 0
				* ctx->img.img_width, i * ctx->img.img_height);
		}
		if (ctx->map[i][size] == '1')
		{
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, size
				* ctx->img.img_width, i * ctx->img.img_height);
			mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.grass, size
				* ctx->img.img_width, i * ctx->img.img_height);
		}
		i++;
	}
}

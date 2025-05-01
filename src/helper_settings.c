/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:15:35 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/29 17:53:08 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_inner_walls(t_drawctx *ctx, int map_lines)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(ctx->map[0]) - 2;
	i = 1;
	while (i < map_lines)
	{
		j = 1;
		while (j < size)
		{
			if (ctx->map[i][j] == '1')
			{
				mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.lights, j
					* ctx->img.img_width, i * ctx->img.img_height);
			}
			j++;
		}
		i++;
	}
}

void	help(t_drawctx *ctx, int num, t_ij ij)
{
	if (num == 1 || num == 0)
		draw_img(ctx, ctx->win, ctx->img.player_right, ij);
	if (num == 2)
		draw_img(ctx, ctx->win, ctx->img.player_left, ij);
	if (num == 3)
		draw_img(ctx, ctx->win, ctx->img.player_down, ij);
	if (num == 4)
		draw_img(ctx, ctx->win, ctx->img.player_up, ij);
}

void	draw_elements(t_drawctx *ctx, int num)
{
	t_ij	ij;

	ij.i = 0;
	while (ctx->map[ij.i])
	{
		ij.j = 0;
		while (ctx->map[ij.i][ij.j++])
		{
			if (ctx->map[ij.i][ij.j] == '0')
				draw_img(ctx, ctx->win, ctx->img.img, ij);
			if (ctx->map[ij.i][ij.j] == 'P')
				help(ctx, num, ij);
			if (ctx->map[ij.i][ij.j] == 'C')
				draw_img(ctx, ctx->win, ctx->img.girl, ij);
			if (ctx->map[ij.i][ij.j] == 'E')
				draw_img(ctx, ctx->win, ctx->img.home, ij);
			if (ctx->map[ij.i][ij.j] == 'M')
			{
				set_enemy_position(ctx, 0);
				mlx_loop_hook(ctx->mlx, move_characters, ctx);
			}
		}
		ij.i++;
	}
	draw_move(ctx);
}

void	draw_img(t_drawctx *ctx, void *win, void *texture, t_ij ij)
{
	mlx_put_image_to_window(ctx->mlx, win, texture, ij.j * ctx->img.img_width,
		ij.i * ctx->img.img_height);
}

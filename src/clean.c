/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:24:45 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/28 21:30:20 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_mlx(t_drawctx *ctx)
{
	if (!ctx)
		return ;
	if (ctx->img.enemy_right)
		mlx_destroy_image(ctx->mlx, ctx->img.enemy_right);
	if (ctx->img.grass)
		mlx_destroy_image(ctx->mlx, ctx->img.grass);
	if (ctx->img.home)
		mlx_destroy_image(ctx->mlx, ctx->img.home);
	if (ctx->img.lights)
		mlx_destroy_image(ctx->mlx, ctx->img.lights);
	if (ctx->img.player_up)
		mlx_destroy_image(ctx->mlx, ctx->img.player_up);
	if (ctx->img.enemy_left)
		mlx_destroy_image(ctx->mlx, ctx->img.enemy_left);
	if (ctx->img.player_down)
		mlx_destroy_image(ctx->mlx, ctx->img.player_down);
	if (ctx->img.player_right)
		mlx_destroy_image(ctx->mlx, ctx->img.player_right);
	if (ctx->img.player_left)
		mlx_destroy_image(ctx->mlx, ctx->img.player_left);
	if (ctx->img.img)
		mlx_destroy_image(ctx->mlx, ctx->img.img);
	if (ctx->img.girl)
		mlx_destroy_image(ctx->mlx, ctx->img.girl);
	if (ctx->win)
		mlx_destroy_window(ctx->mlx, ctx->win);
	if (ctx->mlx)
	{
		mlx_destroy_display(ctx->mlx);
		free(ctx->mlx);
	}
	if (ctx->map)
		free_map(ctx->map);
	free(ctx);
	exit(0);
}



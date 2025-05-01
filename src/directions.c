/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:42:05 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/30 12:46:31 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ij	position(char **map)
{
	t_ij	ij;

	ij.i = 0;
	ij.j = 0;
	if (!map)
		return (ij);
	while (map && map[ij.i])
	{
		ij.j = 0;
		while (map[ij.i][ij.j])
		{
			if (map[ij.i][ij.j] == 'P')
				return (ij);
			ij.j++;
		}
		ij.i++;
	}
	return (ij);
}

t_ij	position_e(char **map)
{
	t_ij	ij;

	ij.i = 0;
	while (map && map[ij.i])
	{
		ij.j = 0;
		while (map[ij.i][ij.j])
		{
			if (map[ij.i][ij.j] == 'E')
				return (ij);
			ij.j++;
		}
		ij.i++;
	}
	return (ij);
}

static void	move_player(int keycode, t_drawctx *ctx, t_ij ij)
{
	if (keycode == ESC)
		close_window(ctx);
	if (keycode == D && ctx->map)
	{
		right(ctx, ij.i, ij.j);
		draw_elements(ctx, 1);
	}
	if (keycode == A && ctx->map)
	{
		left(ctx, ij.i, ij.j);
		draw_elements(ctx, 2);
	}
	if (keycode == S && ctx->map)
	{
		down(ctx, ij.i, ij.j);
		draw_elements(ctx, 3);
	}
	if (keycode == W && ctx->map)
	{
		up(ctx, ij.i, ij.j);
		draw_elements(ctx, 4);
	}
	print_move(ctx->move_count);
}

int	handle_key(int keycode, void *param)
{
	t_ij		ij;
	t_drawctx	*ctx;

	ctx = (t_drawctx *)param;
	ij = position(ctx->map);
	move_player(keycode, ctx, ij);
	return (0);
}

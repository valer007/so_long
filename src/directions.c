/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:35 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/25 18:18:56 by vmakarya         ###   ########.fr       */
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
	if (keycode == D)
	{
		right(ctx->map, ij.i, ij.j);
		draw_elements(ctx, 1);
	}
	if (keycode == A)
	{
		left(ctx->map, ij.i, ij.j);
		draw_elements(ctx, 2);
	}
	if (keycode == S)
	{
		down(ctx->map, ij.i, ij.j);
		draw_elements(ctx, 3);
	}
	if (keycode == W)
	{
		up(ctx->map, ij.i, ij.j);
		draw_elements(ctx, 4);
	}
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

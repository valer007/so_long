/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:55:28 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/29 18:16:23 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_drawctx *ctx)
{
	ctx->img.enemy_left = NULL;
	ctx->img.enemy_right = NULL;
	ctx->img.girl = NULL;
	ctx->img.grass = NULL;
	ctx->img.home = NULL;
	ctx->img.img = NULL;
	ctx->img.lights = NULL;
	ctx->img.player_down = NULL;
	ctx->img.player_left = NULL;
	ctx->img.player_right = NULL;
	ctx->img.player_up = NULL;
	ctx->mlx = NULL;
	ctx->str = NULL;
	ctx->win = NULL;
}

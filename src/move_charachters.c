/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_charachters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:52 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/28 20:24:14 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_enemy(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_enemy_position(t_drawctx *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (ctx->map[i])
	{
		j = 0;
		while (ctx->map[i][j])
		{
			if (ctx->map[i][j] == 'M')
			{
				if (ctx->map[i][j - 1] == '1' && ctx->map[i][j + 1] == '1')
				{
					write(1, "invalide map", 11);
					free_mlx(ctx);
				}
				ctx->i = i;
				ctx->j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	swap(char *ch1, char *ch2)
{
	char	temp;

	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

void	helper(t_drawctx *ctx, t_ij ij, int next_j)
{
	if (ctx->map[ij.i][next_j] == 'P')
	{
		free_mlx(ctx);
	}
	draw_img(ctx, ctx->win, ctx->img.img, ij);
	if (ctx->map[ij.i][next_j] != '1' && ctx->map[ij.i][next_j] != 'C'
		&& ctx->map[ij.i][next_j] != 'E')
	{
		swap(&ctx->map[ij.i][ij.j], &ctx->map[ij.i][next_j]);
		ctx->j = next_j;
		if (ctx->dir == 1)
			draw_img(ctx, ctx->win, ctx->img.enemy_right,
				(t_ij){ij.i, next_j});
		else
			draw_img(ctx, ctx->win, ctx->img.enemy_left,
				(t_ij){ij.i, next_j});
	}
	else
		ctx->dir *= -1;
}

int	move_characters(void *param)
{
	t_drawctx	*ctx;
	t_ij		ij;
	int			next_j;

	ctx = (t_drawctx *)param;
	ctx->frame_count++;
	if (ctx->frame_count < 8000)
		return (0);
	ctx->frame_count = 0;
	ij.i = ctx->i;
	ij.j = ctx->j;
	next_j = ij.j + ctx->dir;
	helper(ctx, ij, next_j);
	return (0);
}

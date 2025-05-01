/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:23 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/30 12:38:01 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectible(char **map)
{
	t_ij	ij;

	ij.i = 0;
	while (map[ij.i])
	{
		ij.j = 0;
		while (map[ij.i][ij.j])
		{
			if (map[ij.i][ij.j] == 'C')
				return (0);
			ij.j++;
		}
		ij.i++;
	}
	return (1);
}

void	right(t_drawctx *ctx, int i, int j)
{
	char	temp;

	if (ctx->map[i][j + 1] == '1' && find_collectible(ctx->map))
		return ;
	else if ((ctx->map[i][j + 1] == '1' || ctx->map[i][j + 1] == 'E')
		&& !find_collectible(ctx->map))
		return ;
	else if (ctx->map[i][j + 1] == 'C')
		ctx->map[i][j + 1] = '0';
	else if (ctx->map[i][j + 1] == 'M')
	{
		if (ctx)
			free_mlx(ctx);
	}
	else if (ctx->map[i][j + 1] == 'E' && find_collectible(ctx->map))
	{
		if (ctx)
			free_mlx(ctx);
	}
	ctx->move_count++;
	temp = ctx->map[i][j];
	ctx->map[i][j] = ctx->map[i][j + 1];
	ctx->map[i][j + 1] = temp;
}

void	left(t_drawctx *ctx, int i, int j)
{
	char	temp;

	if (ctx->map[i][j - 1] == '1' && find_collectible(ctx->map))
		return ;
	else if ((ctx->map[i][j - 1] == '1' || ctx->map[i][j - 1] == 'E')
		&& !find_collectible(ctx->map))
		return ;
	else if (ctx->map[i][j - 1] == 'C')
		ctx->map[i][j - 1] = '0';
	else if (ctx->map[i][j - 1] == 'M')
	{
		if (ctx->map)
			free_mlx(ctx);
	}
	else if (ctx->map[i][j - 1] == 'E' && find_collectible(ctx->map))
	{
		if (ctx->map)
			free_mlx(ctx);
	}
	ctx->move_count++;
	temp = ctx->map[i][j];
	ctx->map[i][j] = ctx->map[i][j - 1];
	ctx->map[i][j - 1] = temp;
}

void	down(t_drawctx *ctx, int i, int j)
{
	char	temp;

	if (ctx->map[i + 1][j] == '1' && find_collectible(ctx->map))
		return ;
	else if ((ctx->map[i + 1][j] == '1' || ctx->map[i + 1][j] == 'E')
		&& !find_collectible(ctx->map))
		return ;
	else if (ctx->map[i + 1][j] == 'C')
		ctx->map[i + 1][j] = '0';
	else if (ctx->map[i + 1][j] == 'M')
	{
		if (ctx->map)
			free_mlx(ctx);
	}
	else if (ctx->map[i + 1][j] == 'E' && find_collectible(ctx->map))
	{
		if (ctx->map)
			free_mlx(ctx);
	}
	ctx->move_count++;
	temp = ctx->map[i][j];
	ctx->map[i][j] = ctx->map[i + 1][j];
	ctx->map[i + 1][j] = temp;
}

void	up(t_drawctx *ctx, int i, int j)
{
	char	temp;

	if (ctx->map[i - 1][j] == '1' && find_collectible(ctx->map))
		return ;
	else if ((ctx->map[i - 1][j] == '1' || ctx->map[i - 1][j] == 'E')
		&& !find_collectible(ctx->map))
		return ;
	else if (ctx->map[i - 1][j] == 'C')
		ctx->map[i - 1][j] = '0';
	else if (ctx->map[i - 1][j] == 'M')
	{
		if (ctx->map)
			free_mlx(ctx);
	}
	else if (ctx->map[i - 1][j] == 'E' && find_collectible(ctx->map))
	{
		if (ctx->map)
			free_mlx(ctx);
	}
	ctx->move_count++;
	temp = ctx->map[i][j];
	ctx->map[i][j] = ctx->map[i - 1][j];
	ctx->map[i - 1][j] = temp;
}

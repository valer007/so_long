/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:30:21 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/22 00:59:47 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void right(char **map, int i, int j)
{
	char temp;

	if(map[i][j + 1] == '1')
		return ;
	temp = map[i][j];
	map[i][j] = map[i][j + 1];
	map[i][j + 1] = temp;
}

void left(char **map, int i, int j)
{
	char temp;
	
	if(map[i][j - 1] == '1')
		return ;    
	temp = map[i][j];
	map[i][j] = map[i][j - 1];
	map[i][j - 1] = temp; 
}

void down(char **map, int i, int j)
{
	char temp;

	if (map[i + 1][j] == '1')
		return ;
	temp =  map[i][j];
	map[i][j] = map[i + 1][j];
	map[i + 1][j] = temp;
}

void up(char **map, int i, int j)
{
	char temp;

	if (map[i - 1][j] == '1')
		return ;
	temp =  map[i][j];
	map[i][j] = map[i - 1][j];
	map[i - 1][j] = temp;
}

t_ij position(char **map)
{
	t_ij ij;

	ij.i = 0;
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

int	handle_key(int keycode, void *param)
{
	t_ij ij;
	t_draw_ctx *test;

	test = (t_draw_ctx *)param;
	ij = position(test->map);
	if (keycode == D)
	{
		right(test->map, ij.i, ij.j);
		draw_elements(test->map, test->img, test->win, 1);
	}
	if (keycode == A)
	{
		left(test->map, ij.i, ij.j);
		draw_elements(test->map, test->img, test->win, 2);
	}
	if (keycode == S)
	{
		down(test->map, ij.i, ij.j);
		draw_elements(test->map, test->img, test->win, 3);
	}
	if (keycode == W)
	{
		up(test->map, ij.i, ij.j);
		draw_elements(test->map, test->img, test->win, 4);
	}
	return (0);
}

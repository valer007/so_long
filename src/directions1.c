/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:23 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/26 17:43:24 by vmakarya         ###   ########.fr       */
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

void	right(char **map, int i, int j)
{
	char	temp;

	if (map[i][j + 1] == '1' && find_collectible(map))
		return ;
	else if ((map[i][j + 1] == '1' || map[i][j + 1] == 'E')
		&& !find_collectible(map))
		return ;
	else if (map[i][j + 1] == 'C')
		map[i][j + 1] = '0';
	else if (map[i][j + 1] == 'M')
		exit(0);
	else if (map[i][j + 1] == 'E' && find_collectible(map))
		exit(0);
	temp = map[i][j];
	map[i][j] = map[i][j + 1];
	map[i][j + 1] = temp;
}

void	left(char **map, int i, int j)
{
	char	temp;

	if (map[i][j - 1] == '1' && find_collectible(map))
		return ;
	else if ((map[i][j - 1] == '1' || map[i][j - 1] == 'E')
		&& !find_collectible(map))
		return ;
	else if (map[i][j - 1] == 'C')
		map[i][j - 1] = '0';
	else if (map[i][j - 1] == 'M')
		exit(0);
	else if (map[i][j - 1] == 'E' && find_collectible(map))
		exit(0);
	temp = map[i][j];
	map[i][j] = map[i][j - 1];
	map[i][j - 1] = temp;
}

void	down(char **map, int i, int j)
{
	char	temp;

	if (map[i + 1][j] == '1' && find_collectible(map))
		return ;
	else if ((map[i + 1][j] == '1' || map[i + 1][j] == 'E')
		&& !find_collectible(map))
		return ;
	else if (map[i + 1][j] == 'C')
		map[i + 1][j] = '0';
	else if (map[i + 1][j] == 'M')
		exit(0);
	else if (map[i + 1][j] == 'E' && find_collectible(map))
		exit(0);
	temp = map[i][j];
	map[i][j] = map[i + 1][j];
	map[i + 1][j] = temp;
}

void	up(char **map, int i, int j)
{
	char	temp;

	if (map[i - 1][j] == '1' && find_collectible(map))
		return ;
	else if ((map[i - 1][j] == '1' || map[i - 1][j] == 'E')
		&& !find_collectible(map))
		return ;
	else if (map[i - 1][j] == 'C')
		map[i - 1][j] = '0';
	else if (map[i - 1][j] == 'M')
		exit(0);
	else if (map[i - 1][j] == 'E' && find_collectible(map))
		exit(0);
	temp = map[i][j];
	map[i][j] = map[i - 1][j];
	map[i - 1][j] = temp;
}

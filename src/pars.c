/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:47:46 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/23 20:07:03 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

static int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	dfs(char **map, int i, int j, int flag)
{
	int	n;
	int	m;

	m = ft_strlen(map[0]);
	n = count_line(map);
	if (i < 0 || j < 0 || i >= n || j >= m)
		return ;
	if (flag == 1)
	{
		if (map[i][j] == '1' || map[i][j] == 'V' || map[i][j] == 'C')
			return ;
		map[i][j] = 'V';
	}
	else
	{
		if (map[i][j] == '1' || map[i][j] == 'V')
			return ;
		map[i][j] = 'V';
	}
	dfs(map, i + 1, j, flag);
	dfs(map, i - 1, j, flag);
	dfs(map, i, j + 1, flag);
	dfs(map, i, j - 1, flag);
}

int	flood_fill_for_e(char **map)
{
	int	i;
	int	j;
	int	success;
	int	flag;

	flag = 1;
	success = 1;
	i = position(map).i;
	j = position(map).j;
	dfs(map, i, j, flag);
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				success = 0;
			j++;
		}
		i++;
	}
	return (success);
}

int	flood_fill_for_c(char **map)
{
	int	i;
	int	j;
	int	success;
	int	flag;

	flag = 0;
	success = 1;
	i = position(map).i;
	j = position(map).j;
	map[position_e(map).i][position_e(map).j] = '1';
	dfs(map, i, j, flag);
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				success = 0;
			j++;
		}
		i++;
	}
	return (success);
}

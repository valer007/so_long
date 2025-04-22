/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:47:46 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/22 20:46:07 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_line(char **map)
{
	int i;

	i = 0;
	while (map[i])
		 i++;
	return (i);
}

static void dfs(char **map, int i, int j)
{
	int n;
	int m;

	m = ft_strlen(map[0]);
	n = count_line(map);
	if(i < 0 || j < 0 || i >= n || j >= m)
		return ;
	if(map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	dfs(map, i + 1, j);
	dfs(map, i - 1, j);
	dfs(map, i, j + 1);
	dfs(map, i, j - 1);
}

void print_map(char **map)
{
	 
	int i  = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;	
	}
}

int flood_fill(char **map)
{
	int i;
	int j;
	int success;

	success = 1;
	i = position(map).i;
	j = position(map).j;
	dfs(map, i, j);
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				success = 0;
			j++;
		}
		i++;
	}
	return (success);
}

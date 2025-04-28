/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:08 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/28 20:14:57 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	**load_and_validate_map(const char *file_name)
{
	int		fd;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1 || check_map(fd) == 0)
	{
		write(1, "Invalid map", 11);
		if (fd != -1)
			close(fd);
		return (NULL);
	}
	close(fd);
	map = create_map(file_name);
	if (!map)
		write(1, "Invalid map", 11);
	return (map);
}

int	validate_and_start(const char *file_name, char **argv)
{
	char	**map;
	char	**copy;

	map = load_and_validate_map(file_name);
	if (!map)
		return (0);
	copy = copy_map(map);
	if (!copy || check_arguments(map) == 0 || !flood_fill_for_e(copy))
	{
		write(1, "Invalid map", 11);
		free_map(copy);
		free_map(map);
		return (0);
	}
	free_map(copy);
	copy = copy_map(map);
	if (!flood_fill_for_c(copy))
	{
		write(1, "Invalid map", 11);
		free_map(copy);
		free_map(map);
		return (0);
	}
	free_map(copy);
	return (start_game(argv, map), 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!validate_and_start(argv[1], argv))
		return (0);
	return (1);
}

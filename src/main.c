/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:08 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/23 17:05:01 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(char **map)
{
	int i;
    char **copy;
	int j;

	i = 0;
	j = 0;
    while (map[i])
        i++;
    copy = malloc((i + 1) * sizeof(char *));
    if (!copy)
        return NULL;
	while (map[j])
	{
		copy[j] = ft_strdup(map[j]);
		j++;
	}
	copy[i] = NULL;
	return (copy);
}

int	main(int argc, char **argv)
{
	char		**map;
	const char	*file_name;
	int			fd;
	char		**copy;

	if (argc != 2)
		return (0);
	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (check_map(fd) == 0)
	{
		write(1, "Invalid map", 11);
		return (0);
	}
	close(fd);
	map = create_map(file_name);
	if (map == NULL)
		return (0);
	copy = copy_map(map);
	if (check_arguments(map) == 0 || !flood_fill_for_C(copy) || !flood_fill_for_E(copy))
	{
		write(1, "Invalid map", 11);
		return (0);
	}
	free_map(copy);
	start_game(argv, map);
}

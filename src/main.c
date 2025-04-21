/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:08 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/21 14:29:08 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	const char	*file_name;
	int			fd;

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
	if (check_arguments(map) == 0)
	{
		write(1, "Invalid map", 11);
		return (0);
	}
	return (start_game(argv, map));
}

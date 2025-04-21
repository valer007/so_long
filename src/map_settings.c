/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:59:48 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/21 20:54:07 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	count_lines(const char *file_name)
{
	int		fd;
	int		line;
	char	*tmp;

	line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	tmp = get_next_line(fd);
	while (tmp)
	{
		line++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (line);
}

char	**create_map(const char *file_name)
{
	char	**map;
	int		i;
	int		fd;
	int		line_count;
	char	*line;

	i = 0;
	line_count = count_lines(file_name);
	if (line_count == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (free(map), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}

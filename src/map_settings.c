/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:08:08 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/29 20:42:37 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_move(t_drawctx *ctx)
{
	char	*str;

	str = ft_itoa(ctx->move_count);
	mlx_string_put(ctx->mlx, ctx->win, 10, 10, 0x0000FF, str);
	free(str);
	str = NULL;
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

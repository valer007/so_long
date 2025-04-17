/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:35:36 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/15 14:26:09 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_char(char ch, int *e, int *c, int *p)
{
	if (ch == 'E')
		(*e)++;
	else if (ch == 'C')
		(*c)++;
	else if (ch == 'P')
		(*p)++;
	else if (ch != '0' && ch != '1' && ch != '\n')
		return (0);
	if (*e > 1 || *p > 1)
		return (0);
	return (1);
}

int	check_arguments(char **map)
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (!validate_char(map[i][j], &e, &c, &p))
				return (0);
			j++;
		}
		i++;
	}
	if (c == 0 || e == 0 || p == 0)
		return (0);
	return (1);
}

static int	check_first_line(char *map, char *first_line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (map[i] != '1')
			return (0);
		first_line[i] = '1';
		i++;
	}
	first_line[len] = '\0';
	return (1);
}

static int	check_body(t_arg *arg, int fd)
{
	arg->map = get_next_line(fd);
	while (arg->map)
	{
		if (arg->map[ft_strlen(arg->map) - 1] == '\n')
			arg->map[ft_strlen(arg->map) - 1] = '\0';
		if (ft_strlen(arg->map) != arg->len || arg->map[0] != '1'
			|| arg->map[arg->len - 1] != '1')
			return (free(arg->map), free(arg->first_line),
				free(arg->last_line), 0);
		free(arg->last_line);
		arg->last_line = ft_strdup(arg->map);
		free(arg->map);
		arg->map = get_next_line(fd);
	}
	if (!arg->last_line
		|| ft_strncmp(arg->last_line, arg->first_line, arg->len) != 0)
		return (free(arg->last_line), free(arg->first_line), 0);
	return (free(arg->last_line), free(arg->first_line), 1);
}

int	check_map(int fd)
{
	t_arg	arg;

	arg.map = get_next_line(fd);
	if (!arg.map)
		return (0);
	arg.len = ft_strlen(arg.map);
	if (arg.map[arg.len - 1] == '\n')
		arg.len--;
	arg.first_line = malloc(arg.len + 1);
	if (!arg.first_line)
		return (free(arg.map), 0);
	if (!check_first_line(arg.map, arg.first_line, arg.len))
		return (free(arg.map), free(arg.first_line), 0);
	free(arg.map);
	arg.last_line = NULL;
	return (check_body(&arg, fd));
}

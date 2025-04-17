/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:51 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/14 22:26:16 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
# include "../libft/libft.h"

typedef struct  s_arg
{
	char	*map;
	char	*first_line;
	char	*last_line;
	size_t	len;
}	t_arg;

int	check_map(int fd);
int count_lines(const char *file_name);
char **create_map(const char *file_name);
void free_map(char **map);
int check_arguments(char **map);

#endif
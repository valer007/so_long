/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:51 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/20 16:20:58 by vmakarya         ###   ########.fr       */
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

typedef struct s_image_path
{
	int img_width;
	int img_height;
	void *mlx;
	void *win;
	void *shenq_img;
	void *lights;
	void *img;
	void *player;
	void *girl;
	void *home;
	
}	t_image_path;

t_image_path	image_path();
int				check_map(int fd);
int				count_lines(const char *file_name);
char			**create_map(const char *file_name);
void			free_map(char **map);
int				check_arguments(char **map);
void			free_map(char **map);
int				count_lines(const char *file_name);
char			**create_map(const char *file_name);
void			checking_map(char **map, int map_lines);
void			checking_map1(char **map);
void			checking_map2(char **map, int map_lines);
void			checking_map3(char **map);

#endif
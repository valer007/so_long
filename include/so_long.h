/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:51 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/21 13:36:07 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_arg
{
	char	*map;
	char	*first_line;
	char	*last_line;
	size_t	len;
}	t_arg;

typedef struct s_img
{
	void	*mlx;
	void	*img;
	void	*shenq_img;
	void	*lights;
	void	*player;
	void	*girl;
	void	*home;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_draw_ctx
{
	t_img	img;
	void	*win;
	int		i;
	int		j;
}	t_draw_ctx;

typedef struct s_ij
{
	int		i;
	int		j;
}	t_ij;

int		check_map(int fd);
int		check_arguments(char **map);
int		count_lines(const char *file_name);
int		start_game(char **argv, char **map);
char	**create_map(const char *file_name);
void	free_map(char **map);

t_img	image_path(void);
void	load_images(t_img *img, void *mlx);
void	draw_top_bottom(char **map, int map_lines, t_img img, void *win);
void	draw_left_right(char **map, t_img img, void *win);
void	draw_inner_walls(char **map, int map_lines, t_img img, void *win);
void	draw_elements(char **map, t_img img, void *win);
void	draw_img(t_img img, void *win, void *texture, t_ij ij);
void	draw_pair(t_img img, void *win, void *texture, t_ij ij);

#endif

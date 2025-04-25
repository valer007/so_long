/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:51 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/25 19:39:29 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define A 0
# define S 1
# define D 2
# define W 13

typedef struct s_character
{
	int		e;
	int		c;
	int		p;
	int		m;
}			t_character;

typedef struct s_arg
{
	char	*map;
	char	*first_line;
	char	*last_line;
	size_t	len;
}			t_arg;

typedef struct s_img
{
	void	*win;
	void	*mlx;
	void	*img;
	void	*shenq_img;
	void	*lights;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*girl;
	void	*home;
	void	*enemy_left;
	void	*enemy_right;
	void	*player_left;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_drawctx
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		i;
	int		j;
	char	**map;
	int		frame_count;
	int		dir;
}			t_drawctx;

typedef struct s_ij
{
	int		i;
	int		j;
}			t_ij;

void		set_enemy_position(t_drawctx *ctx);
int			check_map(int fd);
int			check_arguments(char **map);
int			count_lines(const char *file_name);
int			start_game(char **argv, char **map);
char		**create_map(const char *file_name);
char		**copy_map(char **map);
char		**load_and_validate_map(const char *file_name);
int			validate_and_start(const char *file_name, char **argv);
void		free_map(char **map);
int			flood_fill_for_e(char **map);
int			flood_fill_for_c(char **map);
int			move_characters(void *param);
int			has_enemy(char **map);
t_img		image_path(void);
t_ij		position(char **map);
t_ij		position_e(char **map);
void		load_images(t_img *img, void *mlx);
void		draw_top_bottom(char **map, int map_lines, t_img img, void *win);
void		draw_left_right(char **map, t_img img, void *win);
void		draw_inner_walls(char **map, int map_lines, t_img img, void *win);
void		draw_elements(t_drawctx *ctx, int num);
void		draw_img(t_img img, void *win, void *texture, t_ij ij);
void		draw_pair(t_img img, void *win, void *texture, t_ij ij);
int			handle_key(int keycode, void *param);
void		print_map(char **map);
int			find_collectible(char **map);
void		right(char **map, int i, int j);
void		left(char **map, int i, int j);
void		down(char **map, int i, int j);
void		up(char **map, int i, int j);

#endif

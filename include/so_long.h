/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:51 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/30 12:46:07 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define A 97
# define S 115
# define D 100
# define W 119
# define ESC 65307
# define HEIGHT 60
# define WIDTH 57

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
	void	*img;
	void	*grass;
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
	int		move_count;
	char	*str;
}			t_drawctx;

typedef struct s_ij
{
	int		i;
	int		j;
}			t_ij;

void		print_move(int move);
void		set_enemy_position(t_drawctx *ctx, int num);
void		initialize(t_drawctx *ctx);
int			close_window(t_drawctx *test);
int			check_map(int fd);
void		draw_move(t_drawctx *ctx);
int			check_arguments(char **map);
int			count_lines(const char *file_name);
int			start_game(char **argv, char **map);
char		**create_map(const char *file_name);
char		**copy_map(char **map);
char		**load_and_validate_map(const char *file_name);
int			validate_and_start(const char *file_name, char **argv);
int			flood_fill_for_e(char **map);
int			flood_fill_for_c(char **map);
int			move_characters(void *param);
int			has_enemy(char **map);
t_ij		position(char **map);
void		free_mlx(t_drawctx *ctx);
void		load_images(t_drawctx *ctx);
void		draw_top_bottom(t_drawctx *ctx, int map_lines);
void		draw_left_right(t_drawctx *ctx);
void		draw_inner_walls(t_drawctx *ctx, int map_lines);
void		draw_elements(t_drawctx *ctx, int num);
void		draw_img(t_drawctx *ctx, void *win, void *texture, t_ij ij);
int			handle_key(int keycode, void *param);
int			find_collectible(char **map);
void		right(t_drawctx *ctx, int i, int j);
void		left(t_drawctx *ctx, int i, int j);
void		down(t_drawctx *ctx, int i, int j);
void		up(t_drawctx *ctx, int i, int j);
t_ij		position_e(char **map);
void		free_map(char **map);

#endif

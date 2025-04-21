/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:15:35 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/22 01:18:04 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_inner_walls(char **map, int map_lines, t_img img, void *win)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(map[0]) - 2;
	i = 1;
	while (i < map_lines)
	{
		j = 1;
		while (j < size)
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(img.mlx, win, img.img,
					j * img.img_width, i * img.img_height);
				mlx_put_image_to_window(img.mlx, win, img.lights,
					j * img.img_width, i * img.img_height);
			}
			j++;
		}
		i++;
	}
}

void	help(t_img img, void *win, int num, t_ij ij)
{
	if(num == 1 || num == 0)
		draw_pair(img, win, img.player_right, ij);
	if(num == 2)
		draw_pair(img, win, img.player_left, ij);
	if(num == 3)
		draw_pair(img, win, img.player_down, ij);
	if(num == 4)
		draw_pair(img, win, img.player_up, ij);
}

void	draw_elements(char **map, t_img img, void *win, int num)
{
	t_ij	ij;

	ij.i = 0;
	while (map[ij.i])
	{
		ij.j = 0;
		while (map[ij.i][ij.j])
		{
			if (map[ij.i][ij.j] == '0')
				draw_img(img, win, img.img, ij);
			if (map[ij.i][ij.j] == 'P')
				help(img, win, num, ij);
			if (map[ij.i][ij.j] == 'C')
				draw_pair(img, win, img.girl, ij);
			if (map[ij.i][ij.j] == 'E')
				draw_pair(img, win, img.home, ij);
			ij.j++;
		}
		ij.i++;
	}
}

void	draw_img(t_img img, void *win, void *texture, t_ij ij)
{
	mlx_put_image_to_window(img.mlx, win, texture,
		ij.j * img.img_width, ij.i * img.img_height);
}

void	draw_pair(t_img img, void *win, void *texture, t_ij ij)
{
	draw_img(img, win, img.img, ij);
	draw_img(img, win, texture, ij);
}

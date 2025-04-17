/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:36:08 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/17 18:36:53 by vmakarya         ###   ########.fr       */
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

int close_window()
{
	exit(0);
}

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

	int i  = 0;
	int j = 0;
	
	void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "so_long");

    int img_width = 10;
	int img_height = 10;
    void *img = mlx_xpm_file_to_image(mlx, "assets/blocks.xpm", &img_width, &img_height);

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img, j * img_width, i * img_height);
			j++;
		}
		i++;
	}

	mlx_hook(win, 17, 0, close_window, NULL);

    mlx_loop(mlx);
	free_map(map);
	return (0);
}

// int main(void)
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 800, 600, "Show Image");

//     int img_width = 0;
// 	int img_height = 0;
//     void *img = mlx_xpm_file_to_image(mlx, "assets/blocks.xpm", &img_width, &img_height);

//     mlx_put_image_to_window(mlx, win, img, 100, 100); // Display at (100, 100)

// 	mlx_hook(win, 17, 0, close_window, NULL);
	
//     mlx_loop(mlx);
//     return 0;
// }


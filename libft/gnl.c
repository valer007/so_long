/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:53:48 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/29 17:52:07 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *line)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	len = i + 1;
	if (line[i] == '\n')
		len++;
	new_line = malloc(sizeof(char) * len);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i <= len - 2)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*extract_line(char *buffer)
{
	if (!buffer || !buffer[0])
		return (NULL);
	return (get_line(buffer));
}

static char	*read_and_store(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		str = ft_strjoin_free(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_and_store(fd, str);
	if (!str)
		return (NULL);
	line = extract_line(str);
	str = foo(str);
	if (!line && str)
	{
		free(str);
		str = NULL;
	}
	return (line);
}

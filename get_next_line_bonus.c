/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:45:06 by syonekur          #+#    #+#             */
/*   Updated: 2023/11/29 23:06:54 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char **string)
{
	char	*line;
	char	*new_string;
	char	*newline_pos;

	newline_pos = ft_strchr(*string, '\n');
	if (newline_pos)
	{
		new_string = ft_strdup(newline_pos + 1);
		*(newline_pos + 1) = '\0';
		line = ft_strdup(*string);
		free(*string);
		*string = new_string;
	}
	else
	{
		line = *string;
		*string = NULL;
	}
	return (line);
}

static void	ft_strdel(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

static ssize_t	read_from_fd(int fd, char **string)
{
	char	*buffer;
	ssize_t	read_bytes;
	char	*tmp;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + (size_t)1);
	if (!buffer)
		return (-1);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(*string, buffer);
		if (!tmp)
		{
			free(buffer);
			return (-1);
		}
		ft_strdel(string);
		*string = tmp;
		if (ft_strchr(*string, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	static char	*string[OPEN_MAX + 1];
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_bytes = read_from_fd(fd, &string[fd]);
	if (read_bytes < 0)
	{
		ft_strdel(&string[fd]);
		return (NULL);
	}
	if (read_bytes == 0 && (ft_strlen_s(string[fd]) == 0))
	{
		ft_strdel(&string[fd]);
		return (NULL);
	}
	return (get_line(&string[fd]));
}

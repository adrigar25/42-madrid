/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:04:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 17:47:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_header_map_num(char *file)
{
	int		fd;
	char	*line;
	char	c;
	int		i;

	fd = ft_open_file(file);
	if (fd == -1)
	{
		return (NULL);
	}
	line = NULL;
	i = 0;
	while (read(fd, &c, 1) != '\n')
	{
		line[i] = c;
	}
	if (ft_close_file(fd) == -1)
	{
		return (NULL);
	}
	return (line);
}

int	ft_get_num_header_rows(char *file)
{
	int		fd;
	int		rows;
	char	c;

	fd = ft_open_file(file);
	if (fd == -1)
		return (-1);
	rows = 0;
	while (read(fd, &c, 1) != '\n')
	{
		if (ft_is_digit(c))
			rows = rows * 10 + (c - '0');
		else if (c == '\n')
		{
			ft_close_file(fd);
			return (rows);
		}
	}
	ft_close_file(fd);
	return (rows);
}

char	*ft_get_fills(char *file)
{
	int		fd;
	char	*line;
	char	*fill;
	char	c;
	int		i;

	fd = ft_open_file(file);
	if (fd == -1)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (i >= BUFFER_SIZE)
		{
			free(line);
			ft_close_file(fd);
			return (NULL);
		}
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	if (ft_close_file(fd) == -1)
	{
		free(line);
		return (NULL);
	}
	i = ft_strlen(line);
	if (i < 3)
	{
		free(line);
		return (NULL);
	}
	fill = malloc(sizeof(char) * 4);
	if (!fill)
	{
		free(line);
		return (NULL);
	}
	fill[0] = line[i - 3];
	fill[1] = line[i - 2];
	fill[2] = line[i - 1];
	fill[3] = '\0';
	free(line);
	if (!fill)
	{
		ft_put_error("Error 4: Error reading fills.\n");
		return (NULL);
	}
	return (fill);
}

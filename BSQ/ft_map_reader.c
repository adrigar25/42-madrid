/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:29:42 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/12 17:47:43 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_write_arr(char *file, char **map, int rows, int cols)
{
	int		i;
	char	*line;
	int		fd;
	char	c;

	fd = ft_open_file(file);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) && c != '\n')
		;
	line = (char *)malloc(sizeof(char) * (cols + 1));
	if (!line)
	{
		ft_put_error("Error 5: Memory allocation failed.\n");
		return (0);
	}
	free(line);
	i = 0;
	while (i < rows)
	{
		map[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map[i])
		{
			ft_put_error("Error 7: Memory allocation failed.\n");
			return (0);
		}
		read(fd, map[i], cols);
		map[i][cols] = '\0';
		read(fd, &line, 1);
		i++;
	}
	map[i] = NULL;
	fd = ft_close_file(fd);
	if (fd == -1)
		return (0);
	return (1);
}

char	**ft_map_reader(char *file, char **map, int rows_header)
{
	int	rows;
	int	cols;

	rows = ft_get_document_rows(file);
	if (rows <= 0)
		return (NULL);
	else if (rows == 1)
	{
		ft_put_error("Error 3: Map is empty.\n");
		return (NULL);
	}
	else if ((rows - 2) != rows_header)
	{
		ft_put_error("Error 6: Number of rows in the header does not match the number of rows in the map.\n");
		return (NULL);
	}
	cols = ft_get_document_cols(file);
	if (cols <= 0 || cols == -1 || rows == -1)
	{
		ft_put_error("Error 2: Error reading file.\n");
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
	{
		ft_put_error("Error 4: Memory allocation failed.\n");
		return (NULL);
	}
	ft_write_arr(file, map, rows, cols);
	if (!map)
	{
		ft_put_error("Error 2: Error reading file.\n");
		return (NULL);
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:09:23 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/09 23:18:17 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"
#include <fcntl.h>
#include <unistd.h>

int	open_file(const char *loc_dict)
{
	int	fd;

	fd = open(loc_dict, 0);
	if (fd == -1)
		handle_error("Dict Error: Error 1 - File not found\n", fd, NULL);
	return (fd);
}

int	read_file(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, 4096);
	if (bytes_read == -1)
		handle_error("Dict Error: Error 4 - Read Error\n", fd, NULL);
	return (bytes_read);
}

t_dict	*ft_read_document(char *loc_dict, t_dict *arr_dict)
{
	int		fd;
	char	buffer[4096];

	fd = open_file(loc_dict);
	if (fd == -1)
		return (NULL);
	if (read_file(fd, buffer) == -1)
	{
		close(fd);
		return (NULL);
	}
	arr_dict = allocate_memory_for_dict();
	if (arr_dict == NULL)
	{
		close(fd);
		return (NULL);
	}
	arr_dict = process_buffer(buffer, arr_dict);
	close(fd);
	return (arr_dict);
}

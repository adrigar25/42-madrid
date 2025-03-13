/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_document.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:51:38 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/09 23:30:34 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_dict	*process_buffer(char *buffer, t_dict *arr_dict)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (!is_valid_line(&buffer[i]))
		{
			handle_error("Dict Error: Error 3 - Invalid Line\n", -1, arr_dict);
			return (NULL);
		}
		parse_line(buffer, &i, arr_dict, j);
		j++;
		i++;
	}
	arr_dict[j].digits = -1;
	return (arr_dict);
}

int	is_valid_line(char *line)
{
	int	i;

	i = 0;
	if (!(line[i] >= '0' && line[i] <= '9'))
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != ':')
		return (1);
	i++;
	while (line[i] == ' ')
		i++;
	if (!(line[i] >= 32 && line[i] <= 126))
		return (0);
	while (line[i] >= 32 && line[i] <= 126)
		i++;
	if (line[i] != '\0' && line[i] != '\n')
		return (1);
	return (1);
}

void	handle_error(char *message, int fd, t_dict *arr_dict)
{
	ft_put_error(message);
	if (fd != -1)
		close(fd);
	if (arr_dict != NULL)
		free(arr_dict);
}

t_dict	*allocate_memory_for_dict(void)
{
	t_dict	*arr_dict;
	int		i;

	arr_dict = (t_dict *)malloc(sizeof(t_dict) * 41);
	if (arr_dict == NULL)
	{
		ft_put_error("Dict Error: Error 2 - Memory Allocation Error\n");
		return (NULL);
	}
	i = 0;
	while (i < 41)
	{
		arr_dict[i].first_number = (char *)malloc(100 * sizeof(char));
		arr_dict[i].name = (char *)malloc(150 * sizeof(char));
		if (arr_dict[i].first_number == NULL || arr_dict[i].name == NULL)
		{
			handle_error("Dict Error: Error 2 - Memory Allocation Error\n", -1,
				arr_dict);
			return (NULL);
		}
		i++;
	}
	return (arr_dict);
}

void	parse_line(char *buffer, int *i, t_dict *arr_dict, int j)
{
	int	k;

	arr_dict[j].digits = 0;
	while (buffer[*i] != '\n')
	{
		if (buffer[*i] >= '0' && buffer[*i] <= '9')
		{
			if (buffer[*i] != '0' || (arr_dict[j].digits == 0
					&& buffer[*i] == '0'))
				arr_dict[j].first_number[arr_dict[j].digits] = buffer[*i];
			arr_dict[j].digits++;
		}
		if (buffer[*i] == ':')
		{
			k = *i;
			while (buffer[k] != '\n')
			{
				arr_dict[j].name[k - *i - 1] = buffer[k];
				k++;
			}
			*i = k - 1;
		}
		(*i)++;
	}
}

/*
	*ft_read_document: (Por terminar)
		Es una función que lee el archivo numbers.arr_dict.
		Si el archivo no se encuentra,
			imprime un mensaje de error y retorna NULL.
		Si el archivo se encuentra, retorna el contenido del archivo.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:36:19 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/09 23:14:28 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"
#include <stdio.h>
#include <unistd.h>

void	print_number_name(char *arr, t_dict *arr_dict, int i, int count)
{
	int	j;
	int	exit_loop;

	j = 0;
	exit_loop = 0;
	while (arr_dict[j].digits != -1 && !exit_loop)
	{
		if (count - i % 3)
		{
			if (arr_dict[j].digits == 1
				&& arr_dict[j].first_number[0] == arr[i])
				printf("%s", arr_dict[j].name);
		}
		if (count > 2 && count - i == 1)
		{
			printf("%s", " and ");
			exit_loop = -1;
		}
		else
			exit_loop = 0;
		if (arr_dict[j].digits == count - i
			&& arr_dict[j].first_number[0] == arr[i])
			printf("%s", arr_dict[j].name);
		j++;
	}
}

void	ft_translate_number(char *arr, t_dict *arr_dict)
{
	int	count;
	int	i;

	i = 0;
	count = ft_count_digits(arr);
	while (i < count)
	{
		print_number_name(arr, arr_dict, i, count);
		if (i < count)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

t_dict	*load_dictionary(char *dict)
{
	t_dict	*arr_dict;

	arr_dict = NULL;
	arr_dict = ft_read_document(dict, arr_dict);
	return (arr_dict);
}

int	ft_rush02(char *dict, char *arr)
{
	t_dict	*arr_dict;

	arr_dict = load_dictionary(dict);
	if (arr_dict == NULL)
		return (1);
	ft_translate_number(arr, arr_dict);
	printf("\nNumber: %s\n", arr);
	return (0);
}

/*
	*ft_rush02:
		Recibe el puntero del array enteros.
*/
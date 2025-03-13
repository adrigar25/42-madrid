/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:45 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/01 16:53:04 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	print_result(int arr[4][4]);
int	fill_cells(int *views, int arr[4][4], int row, int col);

int	rush01(int *views)
{
	int	status;
	int	arr_result[4][4];
	int	i;
	int	j;

	i = 0;
	status = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr_result[i][j] = 0;
			j++;
		}
		i++;
	}
	print_result(arr_result);
	return (status);
}

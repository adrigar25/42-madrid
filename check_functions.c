/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:44:23 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/01 17:44:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_boxes(int *row);

/*
** Check if the number is valid in the row and column
*/

int	check_valid(int arr[4][4], int col, int row, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((arr[row][i] == num) || (arr[i][col] == num))
			return (0);
		i++;
	}
	return (1);
}

int check_col(int arr[4][4], int *views, int col)
{
	int i;
	int coldown[4];
	int colup[4];

	i = 0;
	while (i < 4)
	{
		coldown[i] = arr[i][col]; // Asigna los elementos de la columna al arreglo coldown
		colup[i] = arr[3 - i][col]; // Asigna los elementos de la columna en orden inverso al arreglo colup
		i++;
	}
	if (count_boxes(coldown) != views[col]) // Verifica si la cantidad de cajas en el arreglo coldown coincide con la vista desde arriba
		return (0);
	if (count_boxes(colup) != views[4 + col]) // Verifica si la cantidad de cajas en el arreglo colup coincide con la vista desde abajo
		return (0);
	return (1);
}

int check_row(int arr[4][4], int *views, int row)
{
	int i;
	int rowleft[4];
	int rowright[4];

	i = 0;
	while (i < 4)
	{
		rowleft[i] = arr[row][i]; // Asigna los elementos de la fila al arreglo rowleft
		rowright[i] = arr[row][4 - 1 - i]; // Asigna los elementos de la fila en orden inverso al arreglo rowright
		i++;
	}
	if (count_boxes(rowleft) != views[8 + row]) // Verifica si la cantidad de cajas en el arreglo rowleft coincide con la vista desde la izquierda
		return (0);
	if (count_boxes(rowright) != views[12 + row]) // Verifica si la cantidad de cajas en el arreglo rowright coincide con la vista desde la derecha
		return (0);
	return (1);
}

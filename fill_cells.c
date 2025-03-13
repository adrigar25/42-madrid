/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:03:21 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/01 21:03:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_valid(int arr[4][4], int col, int row, int num);
int	check_row(int arr[4][4], int *views, int row);
int	check_col(int arr[4][4], int *views, int col);

int fill_cells(int *views, int arr[4][4], int row, int col)
{
	int num;

	// Si hemos llegado la ultima fila terminamos
	if (row == 4)
		return (1);

	// Si hemos llegado a la columna final, pasamos a la siguiente fila a la primera columna
	if (col == 4)
		return (fill_cells(views, arr, row + 1, 0));

	// Probamos los números del 1 al 4 en la celda actual
	num = 1;
	while (num <= 4)
	{
		// Si el número es válido en la posición actual
		if (check_valid(arr, col, row, num))
		{
			// Asignamos el número a la celda actual
			arr[row][col] = num;

			// Si estamos en la última columna y la fila no cumple con las vistas
			// o si estamos en la última fila y la columna no cumple con las vistas
			// entonces el número asignado no es válido y lo eliminamos
			if ((col == 3 && !check_row(arr, views, row)) || ((row == 3 && !check_col(arr, views, col))))
				arr[row][col] = 0;
			// Si podemos llenar las celdas restantes de forma válida, retornamos 1
			else if (fill_cells(views, arr, row, col + 1))
				return (1);
			// Si no podemos llenar las celdas restantes de forma válida, eliminamos el número asignado
			else
				arr[row][col] = 0;
		}
		num++;
	}
	// Si no podemos llenar las celdas restantes de forma válida, retornamos 0
	return (0);
}

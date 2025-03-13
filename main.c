/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:17:37 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/01 16:48:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	rush01(int *views);
int	*store_input(char *str);

int	main(int argn, char **argv)
{
	int	result;
	int	*views;

	if (argn != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	views = store_input(argv[1]);
	if (!views)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	result = rush01(views);
	if (result == 1)
	{
		write(1, "Error\n", 6);
		free(views);
		return (1);
	}
	free(views);
	return (0);
}

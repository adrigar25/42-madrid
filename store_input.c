/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:12:06 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/01 20:12:15 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*store_input(char *str)
{
	int	*views;
	int	i;
	int	j;

	views = (int *)malloc(16 * sizeof(int));
	if (!views)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			views[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	if (j != 16)
	{
		free(views);
		return (NULL);
	}
	return (views);
}

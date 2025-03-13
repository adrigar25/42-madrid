/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:39:13 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/12 19:56:49 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max || min == max)
		return (NULL);
	range = malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}

// int	main(void)
// {
// 	int *range;
// 	int i;

// 	range = ft_range(-5, 5);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d\n", range[i]);
// 		i++;
// 	}
// 	return (0);
// }
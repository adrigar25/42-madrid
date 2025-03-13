/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:57:15 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/12 20:51:40 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max || min == max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (i);
}

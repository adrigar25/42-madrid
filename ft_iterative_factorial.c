/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:11 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/03 16:39:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	result = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	printf("ft_iterative_factorial: %d\n", ft_iterative_factorial(3));
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:15 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/10 02:33:16 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_fibonacci(int index)
{
	int	result;

	result = 1;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

// int	main(void)
// {
// 	printf("ft_fibonacci: %d\n", ft_fibonacci(6));
// 	return (0);
// }
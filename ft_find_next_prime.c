/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:39:26 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/10 02:33:03 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

// int	main(void)
// {
// 	int	nbrs[13] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 4};
// 	int	i;

// 	i = 0;
// 	while (nbrs[i])
// 	{
// 		printf("find_next_prime: %d - %d\n", nbrs[i],
// 			ft_find_next_prime(nbrs[i]));
// 		i++;
// 	}
// 	return (0);
// }
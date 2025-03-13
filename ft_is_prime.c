/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:15:58 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/10 02:33:13 by agarcia          ###   ########.fr       */
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

// int	main(void)
// {
// 	int nbrs[13] = {4, 17};
// 	int i;
// 	i = 0;
// 	while (nbrs[i])
// 	{
// 		printf("is_prime: %s\n", ft_is_prime(nbrs[i]) ? "primo" : "no primo");
// 		i++;
// 	}
// 	return (0);
// }
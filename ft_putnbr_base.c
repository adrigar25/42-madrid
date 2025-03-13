/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:39:26 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/02 21:39:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;

	if (!is_valid_base(base))
		return ;
	baselen = 0;
	while (base[baselen] != '\0')
		baselen++;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / baselen), base);
		write(1, &base[-(nbr % baselen)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= baselen)
		ft_putnbr_base(nbr / baselen, base);
	write(1, &base[nbr % baselen], 1);
}

// int	main(void)
// {
// 	char	*base;
// 	int		tests[] = {0, 1, -1, 10, -10, 16, -16, 255, -255, 1000, -1000,
// 				2147483647, -2147483648};
// 	int		num_tests;

// 	base = "01234566789ABCDEF";
// 	num_tests = sizeof(tests) / sizeof(tests[0]);
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		ft_putnbr_base(tests[i], base);
// 		write(1, "\n", 1);
// 	}
// 	return (0);
// }

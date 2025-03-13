/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:53:32 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/10 10:40:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		while (*argv[i])
		{
			write(1, &(*argv[i]), 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	ft_rev_params(argc, argv);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:35:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/10 10:39:57 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *argv)
{
	while (*argv)
		write(1, argv++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_print_program_name(argv[0]);
	return (0);
}

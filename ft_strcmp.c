/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:32:15 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/26 14:49:01 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// int	main(void)
// {
// 	char	s1[] = "Hello   ";
// 	char	s2[] = "Helloasd";

// 	printf("%d\n", strcmp(s1, s2));
// 	printf("%d\n", ft_strcmp(s1, s2));
// 	return (0);
// }

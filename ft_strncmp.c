/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:56:24 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/26 15:04:03 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "Hello";
// 	char	s2[] = "Helloasd";

// 	printf("%d\n", strncmp(s1, s2, 10));
// 	printf("%d\n", ft_strncmp(s1, s2, 6));
// 	return (0);
// }

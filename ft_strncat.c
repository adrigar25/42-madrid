/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:28:16 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/26 16:42:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strncat(char *dest, const char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char			dest[50] = "Hello, ";
// 	char			dest2[50] = "Hello, ";
// 	char			src[] = "world!";
// 	unsigned int	nb;

// 	nb = 1;
// 	printf("ft_strncat: %s\n", ft_strncat(dest, src, nb));
// 	printf("strncat: %s\n", strncat(dest2, src, nb));
// 	return (0);
// }

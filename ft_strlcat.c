/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:03 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/26 18:22:06 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <bsd/string.h>
// #include <stdio.h>
// #include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char	dest[50] = "Hello, ";
// 	char	dest2[50] = "Hello, ";
// 	char	src[] = "world!";
// 	size_t	size;

// 	size = 11;
// 	printf("ft_strlcat: %d\n", ft_strlcat(dest, src, size));
// 	printf("ft_strlcat: %s\n", dest);
// 	printf("strlcat: %zu\n", strlcat(dest2, src, size));
// 	printf("strlcat: %s\n", dest2);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:18:15 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/24 18:18:17 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return src_len;
	unsigned int i = 0;
	while (i < size - 1 && src[i])
		dest[i] = src[i++];
	if (size > 0)
		dest[i] = '\0';
	return src_len;
}

int	main(void)
{
	char			dest[10];
	char			src[] = "Hello, World!";
	unsigned int	size;
	unsigned int	result;

	size = 10;
	result = ft_strlcpy(dest, src, size);
	printf("dest: %s\n", dest);
	printf("result: %d\n", result);
	return (0);
}

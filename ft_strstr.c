/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:09:25 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/26 17:32:10 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] && str[i + j] && str[i + j] == to_find[j])
			{
				j++;
			}
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str[] = "Hello, world!";
// 	char	to_find[] = "o";

// 	printf("ft_strstr: %s\n", ft_strstr(str, to_find));
// 	printf("strstr: %s\n", strstr(str, to_find));
// 	return (0);
// }

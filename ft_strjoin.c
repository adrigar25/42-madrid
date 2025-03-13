/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:18:23 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/12 20:58:30 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_len;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][++j])
			total_len++;
		if (i < size - 1)
		{
			j = 0;
			while (sep[++j])
				total_len++;
		}
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

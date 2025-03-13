/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/02/24 15:09:42 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'));
}

char	to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (is_alphanumeric(str[i]))
		{
			if (new_word)
				str[i] = to_uppercase(str[i]);
			else
				str[i] = to_lowercase(str[i]);
			new_word = 0;
		}
		else
		{
			new_word = 1;
		}
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:13:22 by agarcia           #+#    #+#             */
/*   Updated: 2025/03/02 22:13:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_getbase(char *base, int *base_len)
{
	int	i;
	int	j;

	i = 0;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return ;
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
	}
	if (i < 2)
		return ;
	*base_len = i;
}

void	ft_getsign(char *str, int *sign, int *i)
{
	while (str[*i] == '+' || str[*i] == '-' || str[*i] == ' ')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i = *i + 1;
	}
}

int	get_base_value(char c, char *base)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (c == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_value;
	int	base_len;

	ft_getbase(base, &base_len);
	if (base_len < 2)
		return (0);
	sign = 1;
	i = 0;
	ft_getsign(str, &sign, &i);
	result = 0;
	while (str[i] && get_base_value(str[i], base) != 0)
	{
		base_value = get_base_value(str[i], base);
		if (base_value == -1)
			return (0);
		result = result * base_len + base_value;
		i++;
	}
	return (result * sign);
}

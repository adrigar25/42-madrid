/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:49:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 17:52:06 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	*ft_num_caracters(char **argv, int i)
{
	int	*num_caracters;

	num_caracters = (int *)malloc(sizeof(int) * 2);
	num_caracters[0] = ft_get_num_header_rows(argv[i]);
	num_caracters[1] = ft_get_document_cols(argv[i]);
	if (num_caracters[0] == -1 || num_caracters[1] == -1)
	{
		ft_put_error("Error 2: Error reading file.\n");
		return (0);
	}
	return (num_caracters);
}

int	main(int argc, char **argv)
{
	char	**map;
	char	*arr_fills;
	int		i;
	int		*num_caracters;

	map = NULL;

	if(argc < 2)
	{
		ft_put_error("Error 1: No file provided.\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		num_caracters = ft_num_caracters(argv, i);
		map = ft_map_reader(argv[i], map, num_caracters[0]);
		arr_fills = ft_get_fills(argv[i]);
		if (!num_caracters[0] || num_caracters[0] <= 0 || !map || !arr_fills)
			return (0);
		map = ft_check_map(map, arr_fills[0], arr_fills[1], arr_fills[2],
				num_caracters[0], num_caracters[1]);
		ft_put_map(map, num_caracters[0]);
		write(1, "\n", 1);
		free(map);
		free(arr_fills);
		free(num_caracters);
		i++;
	}
	return (1);
}

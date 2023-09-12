/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:24 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 10:35:25 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_header.h"
# include <stdio.h>

int	main()
{
	char **map;
	char file_path[] = "map.dict";
	int	lines = 10;
	int rows = 20;

	map = allocate_mda(lines, rows);
	save_map(map, file_path);
	print_mda(map, lines, rows);

	int 	i;
	int     x_start;
	int     y_start;

	x_start = 0;
	y_start = 0;

	i = mtrx_init(map, x_start, y_start);
	printf("\n %d", i);
	return (0);
}
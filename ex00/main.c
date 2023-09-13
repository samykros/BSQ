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

int	main(void)
{
	char **map;
	char file_path[] = "map";
	int	max_lines;
	int max_columns;

	max_lines = get_max_lines(file_path);
	max_columns = get_max_columns(file_path);
	printf("lines: %i\ncolumns: %i\n", max_lines, max_columns);
	// check map for errors?
	map = allocate_mda(max_lines, max_columns);
	save_map(map, file_path);
	check(map, max_lines, max_columns, 0);
	print_mda(map, max_lines, max_columns);
	free_mda(map, max_lines);
	write(1, "\n", 1);
	return (0);
}
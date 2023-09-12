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

int	main()
{
	char **map;
	char file_path[] = "map";
	int	lines = 10;
	int rows = 20;

	map = allocate_mda(lines, rows);
	save_map(map, file_path);
	print_mda(map, lines, rows);
	return (0);
}
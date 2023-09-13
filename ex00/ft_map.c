/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:06:44 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/13 19:06:47 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_map(int empty, int obstacle, int full)
{
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	return (1);
}

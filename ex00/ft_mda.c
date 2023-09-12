/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:31 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 10:35:31 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	**allocate_mda(int colums, int rows)
{
	int	i;
	char **mtrx;

	i = 0;
	mtrx = malloc(colums * sizeof(char*));
	while (i < colums)
	{
		mtrx[i] = malloc(rows * sizeof(char));
		i++;
	}
	return (mtrx);
}

void	free_mda(char **mtrx, int colums)
{
	int	i;

	i = 0;
	while (i < colums)
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

void print_mda(char **mtrx, int colums, int rows)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while(c < colums)
	{
		while(r < rows)
		{
			write(1, &mtrx[c][r], 1);
			r++;
		}
		if (r == rows)
		{
			c++;
			r = 0;
			write(1, "\n", 1);
		}
	}

}

int	strlength(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] != '\n')
	{
		i++;
	}
	return(i);
}

int mtrx_init(char **mtrx, int i, int x_start, int y_start)
{
	int   x;
	int	  y;
	int   j;

	x_start = 0;
	y_start = 0;
	j = strlength(*mtrx);
	while (i < j)
	{
		x = x_start;
		while (x < i)
		{	
			y = y_start;	
			while (y < i)
			{
				if	(mtrx[x][y] == 'o')
					return(i - 1);
				y++;
			}
			x++;
		}
		i++;
	}
	return (i - 1);
}

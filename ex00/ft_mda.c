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

int mtrx_init(char **mtrx, int i, int xstart, int ystart)
{
	int   x;
	int	  y;
	int   j;

	j = strlength(*mtrx);
	while (i < j)
	{
		y = 0;
		while (y < i)
		{	
			x = 0;	
			while (x < i)
			{
				if	(mtrx[ystart + y][xstart + x] == 'o')
					return(i - 1);
				x++;
			}
			y++;
		}
		i++;
	}
	return (i - 1);
}

void fill(char **mtrx, int i, int xstart, int ystart)
{
	int   j;
	int	  k;
	int   b;

	j = 0;
	b = xstart;
	while (j < i)
	{	
		k = 0;
		xstart = b;
		while (k < i)
		{	
				mtrx[ystart][xstart] = 'x';
				xstart++;
				k++;
			
		}
		ystart++;
		j++;
	}
}

void check(char **mtrx)
{
    int 	i;
	int     xstart;
	int     ystart;

	xstart = 6;
	ystart = 4;
	i = 0;
	i = mtrx_init(mtrx, i, xstart, ystart);
	fill(mtrx, i, xstart, ystart);
	printf("\n %d", i);
}




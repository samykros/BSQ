#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

bool	check_map(int fd);
void	open_file(int *fd);
bool	check_length(int fd, int *line_1, int *line);

int	main()
{
	int	fd;

	open_file(&fd);
	if (check_map(fd))
	{
		write(1, "No errors found\n", 16);
	}
	else
	{
		write(1, "Map error\n", 20);
	}
	close(fd);
	return 0;
}

void	open_file(int *fd)
{
	// checks if we opened the file successfully
	*fd = open("map.dict", O_RDONLY);
	if (*fd == -1)
	{
		write(1, "404\n", 4);
		exit(1);
	}
}

bool	check_map(int fd)
{
	int	line_1;
	int	line;
	
	return check_length(fd, &line_1, &line);
}

bool	check_length(int fd, int *line_1, int *line)
{
	char	c;
	int	i = 0;

	*line_1 = 0; // Inicializa line_1 con un valor que no puede ser una longitud válida
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			if (*line_1 == 0)
			{
		        	// Guarda la longitud de la primera línea
				*line_1 = i;
			}
			else if (i != *line_1)
			{
				// Compara la longitud de las líneas subsiguientes con la longitud de la primera línea
				return false;
			}
			i = 0; // Reinicia el contador para la siguiente línea
		}
		else
		{
			i++; // Incrementa el contador de caracteres en la línea actual
		}
	}
	// Al final del bucle, se guardará la longitud de la última línea
	*line = i;
	// Comprueba si la última línea tiene la misma longitud que las anteriores
	return (*line_1 == -1) || (i == *line_1);
}


/*

All lines must have the same length. CHECK

There’s at least one line of at least one box. CHECK ??

At each end of line, there’s a line break. CHECK ??

The characters on the map can only be those introduced in the first line.

The map is invalid if a character is missing from the first line, or if two char-
acters (of empty, full and obstacle) are identical. CHECK ??

The characters can be any printable character, even numbers.

In case of an invalid map, your program should display map error on the error
output followed by a line break. Your program will then move on to the next
map.

*/

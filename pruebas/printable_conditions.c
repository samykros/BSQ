#include <stdbool.h>
#include <stdio.h>

/*

Check al efo is printable NOT WORKING!!!!!!!!!!!!!

*/

bool	ft_str_is_printable(char empty, char full, char obstacle);
bool	ft_isprint(char c);

int	main ()
{
	char empty = 'Ö';
	char obstacle = '0';
	char full = 'j';
	
	int result = ft_str_is_printable(empty, obstacle, full);
	printf("%d\n", result);
	//printf("Empty:%c Full:%c Obstacle:%c", empty, full, obstacle);
	
	return (0);
}


bool	ft_str_is_printable(char empty, char full, char obstacle)
{
	return ft_isprint(empty) && ft_isprint(full) && ft_isprint(obstacle);
}


bool	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

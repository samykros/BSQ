#include <stdio.h>
#include <stdbool.h>

/*

COnditions for when full, empty or obstacle are the same

*/

bool	conditions(char empty, char obstacle, char full);

int	main ()
{
	int empty = '7';
	int obstacle = '8';
	int full = '7';
	
	int result = conditions(empty, obstacle, full);
	printf("%d\n", result);
	printf("Full: %c\n", full);
	
	return 0;
}

bool	conditions(char empty, char obstacle, char full)
{
	if (empty == obstacle)
	{
		printf("Mal\n");
		return 0;
	}
	while (empty == full || obstacle == full)
	{
		printf("Bien\n");
		full++; // Can I do that? For acsii value. acsii is bucle, if you get to the end it restarts.
	}
	printf("%c\n", full); // why tf is this 9
	return 1;
}

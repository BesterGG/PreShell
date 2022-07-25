#include <stdio.h>

int main(int ac, char **av)
{
	av++;
	while (*av != NULL)
	{
	printf("%s", *av);
	av++;
	if (*av != NULL)
		printf(" ");
	}
	printf("\n");
return (0);
}

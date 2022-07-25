#include <stdio.h>

int main(void)
{
	char *str = 0;
	size_t n = 0;
	printf("$");
	while (getline (&str, &n, stdin) != -1)
	{
		printf("$");
		printf("your lines is: %s", str);
	}
	return (0);
}

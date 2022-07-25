#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = 0;
	size_t n = 0;
	char *token;
	char *btoken;
	printf("$");
	while (getline (&str, &n, stdin) != -1)
	{
		btoken = strdup(str);
		printf("$");
		printf("your lines is: %s", str);
		
		while ((token = strtok_r(btoken, " ", &btoken)))
		{
			printf("%s\n", token);
		}
		printf ("el original %s\n", str);
	}
	return (0);
}

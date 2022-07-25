#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = 0;
	size_t n = 0;
	char *token, * btoken;
	printf("$");
	while (getline (&str, &n, stdin) != -1)
	{
		if (!strtok(str, "\n")) //cortamos \n del enter final al mandar el string
			return (-1);
		btoken = strdup(str); //Backup del string
		token = strtok(btoken, " ");
		printf("$");
		printf("your lines is: %s\n", str);
		
		while (token) // Mientras exista token
		{
			printf("%s\n", token); // printeamos cortando en los espacios como separadores
			token = strtok(NULL, " "); // avanzamos al siguiente substring cortando en el siguiente separador
		}
	}
	return (0);
}

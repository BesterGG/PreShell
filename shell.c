#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	(void) argc;
	char *str = 0;
	size_t n = 0;
	int status;
	char *token;
	char *delim = " \t\n";
	char *alambre[] = {"", NULL};
	printf("$");
	while (getline (&str, &n, stdin) != -1)
	{
		token = strtok(str, delim);
		printf("your lines is: %s", token);
		if (execve(token, alambre, NULL) == -1)
		{
			perror("Error:");
		}
		else
		{
			wait(&status);
			printf("end of child\n");
		}
	}
	free(str);
	return (0);
}

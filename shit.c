#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
	char *str = NULL;
	size_t n = 0;
	int status;
	char *token, *backup_token;
	char *delim = " \t\n";
	char *alambre[] = {"", NULL};
	char *p;

	printf("$");
	while (getline (&str, &n, stdin) != -1)
	{
		backup_token = strdup(str);
		token = strtok(backup_token, delim);
		if(token && fork() == 0)
		{
			if (execve(backup_token, alambre, NULL) == -1)
				perror("Error:");
			free(str);
			free(backup_token);
			break;
		}
		else
			wait(&status);
		printf("$");
		free(str);
		free(backup_token);
	}
	return (0);
}

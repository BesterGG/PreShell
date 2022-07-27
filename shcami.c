#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	char *buffer;
	size_t buffersize = 32;
	int status;
	char *token;
	char *alambre[] = {"", NULL};
	char *delim = " \t\n";
	pid_t id;

	buffer = malloc(buffersize);
	if (buffer == NULL)
		return (1);
	printf("$ ");
	while(1)
	{
		getline(&buffer, &buffersize, stdin);
		token = strtok(buffer, delim);
		id = fork();
		if (token && id == 0)
		{
			if(execve(token, alambre, NULL) == -1)
				perror("Error");
		}
		else if (id == -1)
		{				
			perror("Error");
			break;
		}
		else
		{
			wait(&status);
			free(buffer);
		}

		printf("$ ");
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
(void) argc;
	int status;

	if (fork() == 0)
	{
		printf("From child\n");
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
		printf("end of child\n");
	}
	return (0);
}

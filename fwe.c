#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i = 0;
	int status;
	while (i < 5)
	{
		if (fork() == 0)
			execve(argv[0], argv, NULL);
		else
			wait(&status);
		i++;
	}
	return (0);
}

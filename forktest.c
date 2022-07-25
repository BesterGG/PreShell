#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	printf ("Antes de ejecutar fork\n");
	int x = 1;
	int status;
  
    if (fork() == 0)
        printf("Child has x = %d\n", ++x);
    else
	{
	wait(&status);
        printf("Parent has x = %d\n", --x);
	}	
	printf("termina de ejecutar fork en main\n");
	return (0);
}

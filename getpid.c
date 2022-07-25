#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int pida = getppid();
	printf("pid is %d\n", pida);
	return (0);
}

#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int pida = getpid();
	printf("pid is %d\n", pida);
	return (0);
}

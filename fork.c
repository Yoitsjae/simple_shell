#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("before fork I was single\n");

	fork();

	if (pid == -1)
	{
		perror("unsuccesful\n");
		return 1;
	}
	printf("After fork I became double\n");

	return 0;
}

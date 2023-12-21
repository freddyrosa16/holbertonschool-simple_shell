#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork
 * Return: pid of child
*/
int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		printf("Child Process\n");
	} else
	{
		wait(NULL);
		sleep(30);
		printf("Parent Process\n");
	}
	return (0);
}

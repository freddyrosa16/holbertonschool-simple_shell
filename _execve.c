#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - executes the program pointes to by filename
 * Return: 0 on success
*/
int main(void)
{
	pid_t pid;

	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("ERROR: fork failed\n");
		return (-1);
	}
	if (pid == 0)
	{
		int val = execve(argv[0], argv, NULL);

		if (val == -1)
		{
			perror("ERROR: execve failed\n");
		}
	} else
	{
		wait(NULL);
		printf("Done with execve\n");

	}
	return (0);
}

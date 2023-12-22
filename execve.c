#include "shell.h"
/**
 *_execve - Execute an external command using execve.
 * @array: Array of command and its arguments.
 * Return: This function does not return.
 */
void _excecve(char **array)
{
	int status;

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(array[0], array);
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}

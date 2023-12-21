#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	int status, i = 0;
	char **array;
	pid_t child_pid;

	array = malloc(sizeof(char *) * 1024);

	while(1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "#cisfun$ ", 9);
			getline(&buf, &buf_size, stdin);
		}
		else
		{
			if (getline(&buf, &buf_size, stdin) == -1)
			{
				break;
			}
		}
		token = strtok(buf, "\t\n");
		i = 0;

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		array[i] = NULL;
		child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}
		i = 0;
	}
	free(array);
	free(buf);
	return (0);
}

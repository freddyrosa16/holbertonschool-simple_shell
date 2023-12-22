#include "shell.h"
/**
 */

int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	int len, status, i = 0;
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
		len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n')
		{
			buf[len - 1] = '\0';
		}
		token = strtok(buf, " ");
		i = 0;

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		array[i] = NULL;

		if (strcmp(array[0], "env") == 0)
		{
			char **env_ptr = environ;
			while (*env_ptr != NULL)
			{
				printf("%s\n", *env_ptr);
				env_ptr++;
			}
		}
		else if (strcmp(array[0], "exit") == 0)
		{
			free(array);
			free(buf);
			exit(0);
		}
		else
		{
			child_pid = fork();

			if (child_pid == 0)
			{
				execvp(array[0], array);
				perror("Error");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(&status);
			}
		}
		i = 0;
	}
	free(array);
	free(buf);
	return (0);
}

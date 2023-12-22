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

	/*Allocate memory for the command array*/
	array = malloc(sizeof(char *) * 1024);

	/*Main shell loop*/
	while(1)
	{
		/*Display shell prompt if the input is from a terminal*/
		if (isatty(STDIN_FILENO))
		{
			write(1, "#cisfun$ ", 9);
			getline(&buf, &buf_size, stdin);
		}
		else
		{
			/*Read input if not from terminal*/
			if (getline(&buf, &buf_size, stdin) == -1)
			{
				break; /*Break the loop on the EOD*/
			}
		}
		/*Trim newline character from the input*/
		len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n')
		{
			buf[len - 1] = '\0';
		}
		/*Tokenize the input into an array of strings*/
		token = strtok(buf, " ");
		i = 0;

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		array[i] = NULL; /*Set the last element to NULL for execvp*/

		/*Check for built-in commands: env and exit*/
		if (strcmp(array[0], "env") == 0)
		{
			/*print enviroment variables*/
			char **env_ptr = environ;
			while (*env_ptr != NULL)
			{
				printf("%s\n", *env_ptr);
				env_ptr++;
			}
		}
		else if (strcmp(array[0], "exit") == 0)
		{
			/*Free allocated memory and exit the shell*/
			free(array);
			free(buf);
			exit(0);
		}
		else
		{
			/*Fork a child process to execute external commands*/
			child_pid = fork();

			if (child_pid == 0)
			{
				/*Child process: executes the command*/
				execvp(array[0], array);
				perror("Error"); /*Print an error message if execvp fails*/
				exit(EXIT_FAILURE);
			}
			else
			{
				/*Parent process: wait for the child to finish*/
				wait(&status);
			}
		}
		i = 0; /*Reset array index*/
	}
	/*Free allocated memory before exiting*/
	free(array);
	free(buf);
	return (0);
}

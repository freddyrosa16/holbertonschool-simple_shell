#include "shell.h"
/**
 * tokenize_input - Tokenize input string into an array of strings.
 * @input: Input string to be tokenized.
 * Return: Array of strings (tokens).
 */

char **tokenize_input(char *input)
{
	char *token;
	int i = 0;
	char **array = malloc(sizeof(char *) * 1024);

	token = strtok(input, " ");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, "\t\n");
		i++;
	}
	array[i] = NULL;
	return (array);
}

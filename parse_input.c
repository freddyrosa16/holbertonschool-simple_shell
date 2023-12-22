#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * parse_input - parse input from user into tokens
 * @input: input from user
 * @tokens: array of tokens
 * @tokenc: number of tokens
*/
void parse_input(char *input, char **tokens, int *tokenc)
{
	char *token = strtok(input, " \n");

	*tokenc = 0;
	while (token)
	{
		tokens[*tokenc] = token;
		(*tokenc)++;
		token = strtok(NULL, " \n");
	}
	tokens[*tokenc] = NULL; /*set last element to NULL*/
}

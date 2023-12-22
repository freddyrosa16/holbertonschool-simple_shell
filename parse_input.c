#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * parse_input - parse input from user into tokens
 * @input: input from user
 * @tokens: array of tokens
 * @token_count: number of tokens
*/
void parse_input(char *input, char **tokens, int *token_count)
{
	char *token = strtok(input, " \n");

	*token_count = 0;
	while (token)
	{
		tokens[*token_count] = token;
		(*token_count)++;
		token = strtok(NULL, " \n");
	}
	tokens[*token_count] = NULL; /*set last element to NULL*/
}

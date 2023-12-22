#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[] = "This is a separated word by spaces";
	char *copy, *current;
	char delim[] = " ";
	size_t length;

	copy = strdup(str);
	if (!copy)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	length = strlen(copy);

	current = strtok(copy, " ");
	while (current != NULL)
	{
		printf("%s\n", current);
		current = strtok(NULL, " ");
	}

	free(copy);

	return (0);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t size = 0;
	char *buffer = NULL;

	printf("$ ");
	getline (&buffer, &size, stdin);
	printf("%s", buffer);

	free(buffer);

	return (0);
}

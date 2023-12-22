#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;
char **tokenize_input(char *inpuit);
void _excecve(char **array);
char _getline(size_t *buf_size);

#endif

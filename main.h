#ifndef _HSH_
#define _HSH_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void get_input(char *input);
void parse_input(char *input, char **tokens, int *tokenc);
void handle_sigint(int sig);

#endif

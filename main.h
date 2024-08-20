#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>

char *trim(char *str);
int _isspace(int c);
char **tokenize(char *input);
char *getPath(char *input);
int execute(char *input);

extern char **environ;

#endif

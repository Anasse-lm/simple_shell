#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#ifndef SHELL_H
#define SHELL_H
/* logic functions*/
char *read_line(void);
char **tok_line(char *line);
void displayCommand(char **command);
/*string maniputlation*/
char *_strdup(char *line);
int _strlen(char *str);
void _executeCommand(char **command, int status);
#endif /* SHELL_H*/

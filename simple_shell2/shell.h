#ifndef SHELL_H
#define SHELL_H

/*headers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*prototypes*/
int exec(char **args, char **argv, char **env);
char *removeNewLine(char *line);
char *readLine(void);
size_t _strlen(const char *s);
void loop(char **argv, char **env);
int launch(char **args, char **argv, char **env);
void print_err_msg(char *arg, char *argv);

#endif

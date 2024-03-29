#include "shell.h"

/**
 * hsh_exit - exits the shell
 */
int hsh_exit(char **args)
{
	int stat = 0;

	if (args[1] != NULL)
	{
		stat = _atoi(args[1]);
		exit(stat);
	}
	else
		exit(stat);
}
/**
 * print_env -  prints the current environment
 * Return: 1
 */
int hsh_print_env(char __attribute__((unused))**args)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env++);

	}
	return (1);
}

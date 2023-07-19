#include "shell.h"

/**
 * main - test the program
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 *
 * Return: always 0
 */

int main(int __attribute__((unused))argc, char **argv, char **env)
{

	loop(argv, env);

	return (EXIT_SUCCESS);
}

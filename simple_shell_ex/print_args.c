#include <stdio.h>

/**
 * main - print arguments without using argc
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Always succes)
 */

int main(__attribute__((unused))int argc, char *argv[])
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * split_string - split a string into an array of words
 * @str: the string to split
 * @delim: the delimiter character
 *
 * Return: an array of words
 */
char **split_string(char *str, const char *delim)
{
	char *lineptr = NULL, *lineptr_cp = NULL;
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, tokens_num = 1;

	lineptr = str;
	/* dynamically allocating space for a copy of the lineptr */
	lineptr_cp = malloc(sizeof(char) * strlen(str) + 1);
	if (lineptr_cp == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	strcpy(lineptr_cp, lineptr);
	/* split the string (lineptr) into an array of tokens */
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		tokens_num++;
		token = strtok(NULL, delim);
	}
	tokens = malloc(sizeof(char *) * tokens_num);
	/* Storing each token in the tokens array */
	token = strtok(lineptr_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(tokens[i], token);
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	free(lineptr_cp);

	return (tokens);
}

/**
 * main - test the code
 * @argc: arguments counter
 * @argv: double pointer to the array of arguments
 *
 * Return: 0
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *lineptr = NULL;
	char *prompt = "$ ";
	size_t len = 0;
	ssize_t nch_read;
	int i, j;
	const char *delim = " \n";
	char **tokens;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		nch_read = getline(&lineptr, &len, stdin);
		/* checking whether nch_read fails */
		if (nch_read == -1)
		{
			char *msg = strcat(argv[0], ": No such file or directory\n");
			write(STDERR_FILENO, msg, strlen(msg));
			return (-1);
		}

		/* split the string (lineptr) into an array of tokens */
		tokens = split_string(lineptr, delim);

		/* print array */
		for (j = 0; tokens[j] != NULL; j++)
		{
			write(STDOUT_FILENO, tokens[j], strlen(tokens[j]));
			write(STDOUT_FILENO, " ", 1);
		}
		write(STDOUT_FILENO, "\n", 1);

		/* free memory */
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}

	free(lineptr);
	return (0);
}

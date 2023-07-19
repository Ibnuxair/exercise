#include "shell.h"

/**
 * removeNewLine - removes new line character
 * @line: line to remove the character from
 *
 * Return: the line without newline
*/

char *removeNewLine(char *line)
{
	size_t len = _strlen(line);

	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}

	return (line);
}

/**
 * readLine - reads the line from stdin
 * Return: the line
 */

char *readLine(void)
{
	char *line = NULL, *newLine = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("hsh: getline\n");
			exit(EXIT_FAILURE);
		}
	}

	newLine = removeNewLine(line);
	return (newLine);
}

#include "shell.h"

/**
 * splitLine - split a string into an array of words
 * @line: the string to split
 *
 * Return: a null terminated array of words
 */

char **splitLine(char *line)
{
	char *lineCopy, *token, **tokens;
	int i = 0, tokensNum = 0;
	char *errMsg = "hsh: memory allocation error!";

	lineCopy = malloc(sizeof(char) * (_strlen(line) + 1));
	if (!lineCopy)
	{
		write(STDOUT_FILENO, errMsg, _strlen(errMsg));
		exit(EXIT_FAILURE);
	}
	_strcpy(lineCopy, line);

        token = strtok(lineCopy, DELIM);
	while (token)
	{
		tokensNum++;
		token = strtok(NULL, DELIM);
	}

	tokens = malloc(sizeof(*tokens) * (tokensNum + 1));
	if (!tokens)
	{
                write(STDOUT_FILENO, errMsg, _strlen(errMsg));
                free(lineCopy);
                exit(EXIT_FAILURE);
        }

        _strcpy(lineCopy, line);
        token = strtok(lineCopy, DELIM);
        while (token)
        {
                tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
                if (!tokens[i])
                {
                        write(STDOUT_FILENO, errMsg, _strlen(errMsg));
                        free(lineCopy);
                        free(tokens);
                        exit(EXIT_FAILURE);
                }
                _strcpy(tokens[i], token);
                i++;
                token = strtok(NULL, DELIM);
        }
        tokens[i] = NULL;

        free(lineCopy);
        return tokens;
}

#include "shell.h"

/**
 * get_path - generates the path for each command to execute
 * @cmd: the command to execute
 *
 * Return: the path of the command if it exists, NULL otherwise
 */
char *getPath(char *cmd)
{
	char *path, *pathCpy, *pathToken, *filePath;
	int cmdLen, dirLen;
	struct stat buffer;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	pathCpy = malloc(_strlen(path) + 1);
	if (pathCpy == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	_strcpy(pathCpy, path);

	cmdLen = _strlen(cmd);
	pathToken = strtok(pathCpy, ":");
	while (pathToken != NULL)
	{
		dirLen = _strlen(pathToken);
		filePath = malloc(dirLen + cmdLen + 2);
		if (filePath == NULL)
		{
			perror("Memory allocation error");
			free(pathCpy);
			return (NULL);
		}
		_strcpy(filePath, pathToken);
		_strcat(filePath, "/");
		_strcat(filePath, cmd);

		if (stat(filePath, &buffer) == 0)
		{
			free(pathCpy);
			return (filePath);
		}
		free(filePath);
		pathToken = strtok(NULL, ":");
	}
	free(pathCpy);

	if (stat(cmd, &buffer) == 0)
		return (cmd);

	return (NULL);
}

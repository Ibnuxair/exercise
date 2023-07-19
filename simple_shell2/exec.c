#include "shell.h"

/**
 * exec - executes hsh built-in or creates process
 * @args: the arguments to execute
 * @argv: the argument vector
 * @env: the environment variables
 * Return: 1 if the shell should continue, 0 if it should terminate
 */

int exec(char **args, char **argv, char **env)
{
	size_t i;
	/*int stat;*/
	/* Array of builtin commands */
	char *builtin_cmd[] = {
		"exit",
		"env"
	};
	/* Array of function pointers to handle the built-in commands */
	int (*builtin_func[]) (char **args) = {
		&hsh_exit,
		&hsh_print_env
	};

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < sizeof(builtin_cmd) / sizeof(char *); i++)
	{
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
			return ((*builtin_func[i])(args));
	}


	return (launch(args, argv, env));
}

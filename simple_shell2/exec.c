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
  if (args[0] == NULL)
    {
      return (1);
    }

    return (launch(args, argv, env));
}

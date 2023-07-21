#include "shell.h"
#include <unistd.h>

/**
 * launch - creates a process and waits it to terminate
 * @args: the arguments to execute
 * @env: the environment variables
 * Return: always returns 1, to continue execution.
 */

int launch(char **args, char **argv, char **env)
{
	int from_pipe = !isatty(STDIN_FILENO);
	pid_t pid;
	int status;
	char *cmd, *cmdPath;

	cmd = args[0];
	cmdPath = getPath(cmd);
	if (cmdPath == NULL || access(cmdPath, F_OK) == -1)
	{
		print_err_msg(args[0], argv[0]);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			/*Child process*/
			if (execve(cmdPath, args, env) == -1)
			{
				print_err_msg(args[0], argv[0]);
			}
		}
		else if (pid < 0)
		{
			/*Error forking*/
			perror("hsh");
		}
		else
		{
			/*Parent process*/
			do {
				waitpid(pid, &status, WUNTRACED);
				if (!from_pipe)
					write(STDOUT_FILENO, "($)\n", 4);
				else
					write(STDOUT_FILENO, "$\n", 2);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	if (cmdPath != NULL && cmdPath != cmd)
		free(cmdPath);

	return (1);
}

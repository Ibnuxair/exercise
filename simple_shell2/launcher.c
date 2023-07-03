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
	pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) 
    {
        /*Child process*/
        if (execve(args[0], args, env) == -1) 
        {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
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
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

  return (1);
}

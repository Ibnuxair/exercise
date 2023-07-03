#include "shell.h"

/**
 * loop - main loop
 * @argv: argument vector
 * @env: environment variable
*/
void loop(char **argv, char **env)
{
    int status, from_pipe = !isatty(STDIN_FILENO);
    char *line, *args[2];

    do {
        if (!from_pipe)
            write(STDOUT_FILENO, "$ ", 2);
        line = readLine();
        args = splitLine(line);
        status = exec(args, argv, env);

        if (from_pipe)
             write(STDOUT_FILENO, "$ ", 2);

    }   while (status);
    
}
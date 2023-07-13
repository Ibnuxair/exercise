#include "shell.h"

/**
 * loop - executes the main loop
 * @argv: argument vector
 * @env: environment variable
 */

void loop(char **argv, char **env)
{
  int from_pipe = !isatty(STDIN_FILENO);
  char *line, *args[2];
  size_t status;
  
  do {
    if (!from_pipe)
    {
      /*interactive mode*/
      write(STDOUT_FILENO, "($) ", 4);
      line = readLine();

      args[0] = line;
      args[1] = NULL;
      status = exec(args, argv, env);
    }
    else
    {
      /*non_interactive mode*/
      line = readLine();

      args[0] = line;                                                                                                                                                            args[1] = NULL;                                                                                                                                                            status = exec(args, argv, env);
    }

    free(line);
    
  } while (status);
  
}

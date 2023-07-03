#include "shell.h"

int main(int argc, char **argv, char **env)
{
    if (argc < 1 || argc > 1)
        return (1);

    loop(argv, env);

    return (EXIT_SUCCESS);
}
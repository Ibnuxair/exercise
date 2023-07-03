#include "shell.h"

/**
 * splitLine - splits the line entered by a user
 * @line: the line to split
 * 
 * reurn: null termineted array of args
*/

char **slitLine(char *line)
{
    char *args[2];

    args[0] = line;
    args[1] = NULL;

    return (args);   
}
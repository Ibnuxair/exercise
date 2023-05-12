#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *lineptr = NULL;
	char *err_msg = "./shel: No such file or directory";
	size_t len = 0;

	while (1)
	{
		// print the prompt
		write(STDOUT_FILENO, "$ ", 2);

		// read input from the user
		if (getline(&lineptr, &len, stdin) == -1)
		{
			// print an error message and exit the program
			write(STDOUT_FILENO, err_msg, strlen(err_msg));
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
	    }

	    // print the user's input
	    write(STDOUT_FILENO, lineptr, len);
    }

    // free the memory allocated by getline()
    free(lineptr);

    return (0);
}

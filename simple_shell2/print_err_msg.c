#include "shell.h"

/**
 * print_err_msg - prints error message
 * @arg: argument array
 * @argv: arguments vector
*/

void print_err_msg(char *arg, char *argv)
{
	const char *err_msg4 = "not found\n";
	size_t arg_len = _strlen(arg);
	size_t argv_len = _strlen(argv);
	size_t err_msg4_len = _strlen(err_msg4);

	write(STDERR_FILENO, argv, argv_len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "1", 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg, arg_len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_msg4, err_msg4_len);
}

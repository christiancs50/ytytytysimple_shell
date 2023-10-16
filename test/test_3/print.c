#include "shell.h"

/**
 * _print - function that prints string given
 * @message: message to be printed
 *
 */

void _print(const char *message)
{
	write(STDOUT_FILENO, message, str_len(message));
}

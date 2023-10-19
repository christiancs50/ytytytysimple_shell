#include "shell.h"

/**
 * _print - spits out a string on standard output.
 * @message: The string to be written.
 */
void _print(const char *message)
{
	write(1, message, str_length(message));
}


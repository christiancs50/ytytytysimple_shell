#include "shell.h"

/**
 * shell_prompt - function that prints shell prompt
 *
 */

void shell_prompt(void)
{
	if (isatty(STDIN_FILENO == 1) && isatty(STDOUT_FILENO) == 1)
	{
		identify.interactive = 1;
	}

	if (identify.interactive)
	{
		_print ("# "); /* Display shell prompt */
	}
}

#include "shell.h"

/**
 * sig_handler(int signum)
 * @signum: The signal number
 *
 */

void sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		_print("\n");
	}

	else if (signum == SIGTSTP)
	{
		_print("\n");
	}

	exit(EXIT_SUCCESS);
}


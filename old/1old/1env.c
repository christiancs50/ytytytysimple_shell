#include "shell.h"

/**
 * env_buildin - Function to print current environment variables
 */

void env_buildin(void)
{
	char **pcenv = environ;

	while (*pcenv != NULL)
	{
		_print(*pcenv);
		_print("\n");
		pcenv++;
	}
}

/**
 * exit_builtin - Function to exit the shell
 */
void exit_builtin(void)
{
    _print("Exiting the shell.\n");
    exit(EXIT_SUCCESS);
}

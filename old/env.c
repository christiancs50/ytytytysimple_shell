#include "shell.h"

/**
 * env_builtin - Fuction to print current environment variables
 */

void env_builtin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_print(*env);
		_print("\n");
		env++;
	}
}

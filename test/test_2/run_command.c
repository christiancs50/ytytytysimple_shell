#include "shell.h"

/**
 * run_command - Function to execute a command
 * @args: the arrayh of command and its arguments
 */

void run_command(char *args[])
{
	int status;
	pid_t child_pid = fork();

	if  (child_pid == -1)
	{
		/*perror("fork");*/
		_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (access(args[0], X_OK) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}

		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
	waitpid(child_pid, &status, 0);

	}
}


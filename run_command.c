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
		_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			execute_command_from_path(args);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);

	}
}


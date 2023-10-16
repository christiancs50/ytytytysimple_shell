#include "shell.h"

/**
 * run_command - Function to execute a command
 * @args: the arrayh of command and its arguments
 */

void run_command(char *args[])
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		 
		if ( access(args[0], X_OK) == 0)

		{
			void execute_command_from_path(char *args[]);
		}
		else
		{
				_print(args[0]);
				_print(": not found path\n");
				exit(EXIT_FAILURE);
		}

	}
	else
	{
	waitpid(child_pid, &status, 0);

	}
}


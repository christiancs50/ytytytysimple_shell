#include "shell.h"

/**
 * run_command - Function to execute a command
 * @pcargs: the array of command and its arguments
 */
void run_command(char *pcargs[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (strcmp(pcargs[0], "exit") == 0)
		{
			exit_builtin();
		}
		else
		{
			if (access(pcargs[0], X_OK) == -1)
			{
				enact_command_from_path(pcargs);
				exit(EXIT_FAILURE);
			}

			if (execve(pcargs[0], pcargs, NULL) == -1)
			{
				perror("execve");
				fprintf(stderr, "Error executing command: %s\n", pcargs[0]);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}

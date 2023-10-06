#include "shell.h"

/**
 * run_command - Function to execute a command
 * @command: the command to execute
 */

void run_command(const char *command)
{
	int status;
	pid_t child_pid = fork();
	char *const arguments[] = {"/bin/sh", "-c", (char *)command, NULL};

	if  (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve("/bin/sh", arguments, NULL) == -1)
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


#include "shell.h"

/**
 * run_command - Function to execute a command
 * @command: the command to execute
 */

void run_command(const char *command)
{
	char command_buffer[MAX_INPUT_SIZE];
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
		char *arguments[] = {"/bin/sh", "-c", NULL, NULL};

		strncpy(command_buffer, command, sizeof(command_buffer));
		command_buffer[sizeof(command_buffer) -1] = '\0';

		arguments[2] = command_buffer;

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


#include "shell.h"
/**
 * execute_command_from_path - Function to execute a command found in the PATH
 * @command: the command to execute
 * @args: the array of command and its arguments
 */

void execute_command_from_path(char *args[])
{
	int status;
	pid_t child_pid;
	char cmd_buffer[MAX_INPUT_SIZE];
	char *token = strtok(getenv("PATH"), ":");
	int found = 0;

	while (token != NULL)
	{
		snprintf(cmd_buffer, sizeof(cmd_buffer), "%s/%s", token, args[0]);

		if (access(cmd_buffer, X_OK) == 0)
		{
			found = 1;
			break;
		}
	token = strtok(NULL, ":");
	}
	if (!found)
	{
		_print("Command not found in PATH.\n");
		 exit(EXIT_FAILURE);
	}
	child_pid = fork();

	if (child_pid == -1)
	{
		_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd_buffer, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(child_pid, &status, 0);
}
/*
void execute_command_from_path(char *args[]) {
    int status;
    pid_t child_pid;
    char cmd_buffer[MAX_INPUT_SIZE];
    char *token = strtok(getenv("PATH"), ":");
    int found = 0;

    while (token != NULL) {
        snprintf(cmd_buffer, sizeof(cmd_buffer), "%s/%s", token, args[0]);

        if (access(cmd_buffer, X_OK) == 0) {
            found = 1;

            child_pid = fork();

            if (child_pid == -1) {
                _print("Error forking process.\n");
                exit(EXIT_FAILURE);
            } else if (child_pid == 0) {
                if (execve(cmd_buffer, args, NULL) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            } else {
                waitpid(child_pid, &status, 0);
                return; 
            }
        }
        token = strtok(NULL, ":");
    }

    if (!found) {
        _print("Command not found in PATH.\n");
        exit(EXIT_FAILURE);
    }
}*/

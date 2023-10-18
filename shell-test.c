#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024


/**
 * enact_pc_command - Execute a command in a child process
 * @command: The command to execute
 */
void enact_pc_command(char *command)
{
	pid_t pcpid = fork();

	if (pcpid == -1)
	{
		perror("fork");
		return;
	}

	if (pcpid == 0)
	{
		char *argv[3];
		argv[0] = "sh";
		argv[1] = "-c";
		argv[2] = command;

		if (execvp("sh", argv) == -1)
		{
			perror(command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pcpid, &status, 0);
	}
}


/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char insert[MAX_INPUT_SIZE];
	size_t length;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(insert, MAX_INPUT_SIZE, stdin) == NULL)
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		length = strlen(insert);

		if (length > 0 && insert[length - 1] == '\n')
		{
			insert[length - 1] = '\0';
		}

		enact_pc_command(insert);
	}

	return (0);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * enact_command - Execute a command in a child process
 * @command: The command to execute
 */
void enact_command(char *command)
{
	pid_t pcpid = fork();

	if (pcpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pcpid == 0)
	{ /* Child process */
		if (execlp(command, command, NULL) == -1)
		{
			perror(command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{ /* Parent process */
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
		printf("#cisfun$ ");
		fflush(stdout);

		if (fgets(insert, MAX_INPUT_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}

		length = strlen(insert);

		if (length > 0 && insert[length - 1] == '\n')
		{
			insert[length - 1] = '\0';
		}

		enact_command(insert);
	}

	return (0);
}

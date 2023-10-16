#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * enact_command - Execute a command with arguments in a child process
 * @command: The command to execute
 * @pcargs: Array of arguments (including the command)
 */
void enact_command(char *command, char *pcargs[])
{
	pid_t pcpid = fork();

	if (pcpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pcpid == 0)
	{ /* Child process */
		if (execve(command, pcargs, NULL) == -1)
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

	while (1)
	{
		char *pc_token = strtok(insert, " \n");
                char *command = pc_token;
                char *pcargs[MAX_INPUT_SIZE];
                int arg_count = 1;

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

		pc_token = strtok(insert, " \n");
		command = pc_token;
		pcargs[0] = command;

		/* Tokenize the input to separate command and arguments */
		while (pc_token != NULL)
		{
			pc_token = strtok(NULL, " \n");
			pcargs[arg_count++] = pc_token;
		}

		enact_command(command, pcargs);
	}

	return (0);
}

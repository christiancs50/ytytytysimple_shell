#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define PATH_MAX 4096

/**
 * _strcmp - compares two strings character by character
 * @s1: First string to be compared
 * @s2: Second string to be compared
 *
 * Return: An integer (s1 - s2)
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * command_exists - checks if a given command exists in the system's PATH.
 * @command: The command to be checked for existence.
 *
 * Return: If found 1, otherwise 0
 */
int command_exists(char *command)
{
	char *pc_path = getenv("PATH");
	char *pc_token = strtok(pc_path, ":");
	char full_pc_path[PATH_MAX];

	while (pc_token != NULL)
	{
		snprintf(full_pc_path, PATH_MAX, "%s/%s", pc_token, command);

		if (access(full_pc_path, X_OK) == 0)
		{
			return (1); /* Command found */
		}

		pc_token = strtok(NULL, ":");
	}

	return (0); /* Command not found */
}


/**
 * enact_command - executes a command with arguments using fork & execve
 * @command: The command to be executed
 * @pcargs: An array of strings representing the command and its arguments.
 *
 * Return: Void
 */
void enact_command(char *command, char *pcargs[])
{
	pid_t pcpid;

	if (!command_exists(command))
	{
		fprintf(stderr, "Command not found: %s\n", command);
		return;
	}

	pcpid = fork();

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
 * main - entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void);
int main(void)
{
	char insert[MAX_INPUT_SIZE];

	while (1)
	{
		char *pc_token;
		char *command;
		char *pcargs[MAX_INPUT_SIZE];
		int arg_count = 1;

		printf(":) ");
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

		/* Tokenize the input to separate command and arguments */
		pc_token = strtok(insert, " \n");
		command = pc_token;
		pcargs[0] = command;

		/* Check if the command exists before forking */
		if (!command_exists(command))
		{
			fprintf(stderr, "Command not found: %s\n", command);
			continue; /* Skip to the next iteration */
		}

		while (pc_token != NULL)
		{
			pc_token = strtok(NULL, " \n");
			pcargs[arg_count++] = pc_token;
		}

		enact_command(command, pcargs);
	}

	return (0);
}

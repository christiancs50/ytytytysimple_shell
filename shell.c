#include "shell.h"

/**
 * main - Function is the entry point for my simple shell program
 * @ac: argument count(but silenced)
 * @argv: array of strings(but silenced
 * Return: 0
 */

int main(int ac, char **argv)
{
	int num_args;
	char *args[MAX_ARGUMENTS];
	(void) ac;
	(void) argv;

	signal(SIGINT, sig_handler);
	signal(SIGSTOP, sig_handler);

	while (1)
	{
		char *command = read_user_command();

		if (command == NULL)
		{
			break;
		}

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		if (strcmp(command, "env") == 0)
		{
			env_builtin();
		}

		num_args = tokenize_command(command, args);

		if (num_args > 0)
		{
			run_command(args);
		}
		free(command);

	}

	return (0);
}

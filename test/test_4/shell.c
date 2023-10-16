#include "shell.h"

/**
 * main - Function is the entry point for my simple shell program
 * Return: 0
 */



int main(int argc, char *argv[])
{
	int num_args;
	char *args[MAX_ARGUMENTS];

	if (argc == 2)
	{
		FILE *script_file = fopen(argv[1], "r");
		if (script_file == NULL)
		{
			perror("Error opening script");
			return 1;
		}

	
		while (1)
       		{
			 char *command = read_user_command();

			if (command == NULL)
			{
				break;
			}

			num_args = tokenize_command(command, args);

			if (num_args > 0)
			{
				run_command(args);
			}

			free(command);
		}
		fclose(script_file);
	}
	else
	{

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
	}

	return (0);
}

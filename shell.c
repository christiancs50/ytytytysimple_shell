#include "shell.h"

int main(void)
{
	int num_args;
	char *args[MAX_ARGUMENTS];

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

		num_args = tokenize_command(command, args);

		if (num_args > 0)
		{
			if (command[0] == '/')
			{
				run_command(args);
			}
			else
			{
				execute_command_from_path(args);
			}
		}

	free(command);
	}

    return 0;
}


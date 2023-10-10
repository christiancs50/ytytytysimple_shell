#include "shell.h"

int main(void)
{
	int num_args;
	char *args[MAX_ARGUMENTS];

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

    return 0;
}


#include "shell.h"

/**
 * main - entry point for functions
 * Return: 0 as success
 */
int main(void)
{
	char *insert;
	char *pcargs[2];

	while (1)
	{
		insert = read_user_command();

		if (insert == NULL)
			break;

		pcargs[0] = insert;
		pcargs[1] = NULL;

		enact_command_from_path(pcargs);

		free(insert);
	}

	return (0);
}


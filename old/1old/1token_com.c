#include "shell.h"

/**
 * tokenize_command - Function that splits a command string into args.
 * @command: the input command string to tokenize
 * @pcargs: An array to store the resulting arguments
 * Return: the number of arguments found
 */
int tokenize_command(char *command, char *pcargs[])
{
	int num_pcargs = 0;
	char *pctoken = strtok(command, " ");

	while (pctoken != NULL && num_pcargs < MAX_ARGUMENTS)
	{
		pcargs[num_pcargs++] = pctoken;
		pctoken = strtok(NULL, " ");
	}

	pcargs[num_pcargs] = NULL;
	return (num_pcargs);
}

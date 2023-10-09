#include "shell.h"
/**
 * tokenize_command - Function that splits a command string into args..
 * @command: the inpur command string to tokenize
 * @args: An array to store the resulting arguments
 * Return:the number of arguments found
 */

int tokenize_command(char *command, char *args[])
{
	int num_args = 0;
	char *token = strtok(command, " ");

	while (token != NULL && num_args < MAX_ARGUMENTS)
	{
		args[num_args++] = token;
		token = strtok(NULL, " ");
	}

	args[num_args] = NULL;
	return (num_args);
}

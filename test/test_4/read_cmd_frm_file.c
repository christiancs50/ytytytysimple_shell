#include "shell.h"


char *read_cmd_from_file(FILE *file)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&input, &len, file);

	if (read == -1)
	{
		free(input);
		return NULL;
	}

	if (input[read -1] == '\n')
	{
		input[read - 1] = '\0';
	}
	return (input);
}

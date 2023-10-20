#include "shell.h"

/**
 * read_user_command - Function that read user input
 *
 * this function reads a line from the stdio and returns as a
 * dunamic allocated string.
 *
 * Return: Apointer to the user's input string, or Null on fail
 */

char *read_user_command(void)
{
	char *input;
	size_t readbyte;
	size_t input_Length;

	input = (char *) malloc(MAX_INPUT_SIZE);

	if (input == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	memset(input, 0, MAX_INPUT_SIZE);

	shell_prompt();
	readbyte = read(STDIN_FILENO, input, MAX_INPUT_SIZE);

	if (readbyte == (size_t) -1)
	{
		perror("read");
		free(input);
		return (NULL);
	}

	if (readbyte == 0)
	{
		_print("\n");
		free(input);
		return (NULL);
	}

	input_Length = str_len(input);
	if (input_Length > 0 && input[input_Length - 1] == '\n')
	{
		input[input_Length - 1] = '\0';
	}

	return (input);
}

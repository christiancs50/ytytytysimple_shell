#include "shell.h"

/**
 * read_user_command: Function that read user input
 */
 
char *read_user_command(void)
{
	char *input;
	size_t readbyte;
	size_t input_Length;

	input = (char*) malloc( MAX_INPUT_SIZE);

	if (input == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	shell_prompt();
	readbyte = read(STDIN_FILENO, input, MAX_INPUT_SIZE);

	if(readbyte == (size_t) -1)
	{
		perror("read");
		free(input);
		exit(EXIT_FAILURE);
	}

	if(readbyte == 0)
	{
		free(input);
		return (NULL);
	}

	input_Length = str_len(input);
	if(input_Length > 0 && input[input_Length - 1] == '\n')
	{
		input[input_Length - 1] = '\0';
	}

	return (input);
}

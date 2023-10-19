#include "shell.h"

/**
 * read_user_command - Function that reads user input
 *
 * This function reads a line from stdin and returns it as a dynamically
 * allocated string.
 *
 * Return: A pointer to the user's input string, or NULL on failure
 */
char *read_user_command(void)
{
	char *insert;
	size_t perusebyte;
	size_t insert_Length;

	insert = (char *)malloc(MAX_INPUT_SIZE);

	if (insert == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	shell_prompt();
	perusebyte = read(STDIN_FILENO, insert, MAX_INPUT_SIZE);

	if (perusebyte == (size_t)-1)
	{
		perror("read");
		free(insert);
		exit(EXIT_FAILURE);
	}

	if (perusebyte == 0)
	{
		free(insert);
		return (NULL);
	}

	insert_Length = str_length(insert);
	if (insert_Length > 0 && insert[insert_Length - 1] == '\n')
	{
		insert[insert_Length - 1] = '\0';
	}

	return (insert);
}


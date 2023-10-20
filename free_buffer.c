#include "shell.h"

/**
 * free_buffers - function that frees memory with array of strings
 * @buffers: pointer to the string
 */

void free_buffers(char *buffers[])
{
	int i = 0;

	while (buffers[i] != NULL)
	{
		free(buffers[i]);
		i++;
	}
}

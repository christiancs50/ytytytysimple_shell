#include "shell.h"

/* free_buffer -
 *
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

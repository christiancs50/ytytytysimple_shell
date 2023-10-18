#include "shell.h"

/**
 *
 * main - Parent ID
 *
 * Return : 0
 */

int main(void)
{
	pid_t parent_ppid;

	parent_ppid = getppid();
	printf("%u\n",parent_ppid);
	return (0);
}

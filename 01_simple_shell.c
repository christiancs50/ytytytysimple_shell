#include "main.h"

int main(void)
{
	char *pc_line;
	size_t length = 0;
	ssize_t peruse;

	while (1)
	{
		printf("#cisfun$ ");
		peruse = getline(&pc_line, &length, stdin);

		if (peruse == -1)
		{
			if (feof(stdin)) /* Handle end-of-file (Ctrl+D) */
			{
				printf("\n");
				free(pc_line);
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}

		pc_line[peruse - 1] = '\0'; /* Remove the newline character */

		printf("%s\n", pc_line);

		if (enact_pc_command(split_insert(pc_line)) == -1)
		{
			fprintf(stderr, "./shell: No such file or directory\n");
		}
		free(pc_line);
	}

	return (0);
}

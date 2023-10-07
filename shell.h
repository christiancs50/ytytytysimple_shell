#ifndef SHELL_H
#define SHELL_H

/* heasderfiles */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
/* prototypes */

int str_len(const char *s);
void shell_prompt(void);
void run_command(const char *command);
char *read_user_command(void);
void _print(const char *message);

#endif /* SHELL_H */

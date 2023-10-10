#ifndef SHELL_H
#define SHELL_H

/* heasderfiles */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 50
/* prototypes */

int tokenize_command(char *command, char *args[]);
int str_len(const char *s);
void shell_prompt(void);
void run_command(char *args[]);
char *read_user_command(void);
void _print(const char *message);
void execute_command_from_path(char *args[]);
#endif /* SHELL_H */

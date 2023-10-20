#ifndef SHELL_H
#define SHELL_H


/* heasderfiles */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 50
/* prototypes */

int tokenize_command(char *command, char *args[]);
int str_len(const char *s);
void shell_prompt(void);
void run_command(char *args[]);
void free_buffers(char *buffers[]);
char *read_user_command(void);
void _print(const char *message);
void sig_handler(int signum);
void execute_command_from_path(char *args[]);
void env_builtin(void);
extern char **environ;
int command_exist(const char *command);

/**
 * struct identify - defines a stuct named 'idenfify'
 * @interactive:store a Boolean value
 * Description:it definnes an instance with the same name
 */
struct identify
{
	bool interactive;
} identify;
#endif /* SHELL_H */

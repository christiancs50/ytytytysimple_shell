#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 600
#define MAX_ARGUMENTS 300

/* Function prototypes */
int tokenize_command(char *command, char *pcargs[]);
int str_length(const char *s);
void shell_prompt(void);
void run_command(char *pcargs[]);
char *read_user_command(void);
void _print(const char *message);
void sig_handler(int signum);
void enact_command_from_path(char *pcargs[]);
void env_buildin(void);
extern char **environ;
int command_exist(const char *command);
void exit_builtin(void);

#endif /* SHELL_H */

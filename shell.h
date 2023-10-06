#ifndef SHELL_H
#define SHELL_H

/* heasderfiles */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* prototypes */

int str_len(char *s);
void shell_prompt(void);
void run_command(const char *command)

#endif /* SHELL_H */

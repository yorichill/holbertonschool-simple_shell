#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Prototypes */
char **split_line(char *line);
void execute_command(char **args, char *prog_name);
char *get_path(char *command); /* Nouvelle fonction */

#endif
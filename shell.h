#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Accès à l'environnement système pour execve */
extern char **environ;

/* Prototypes des fonctions */
char **split_line(char *line);
void execute_command(char **args, char *prog_name);

#endif

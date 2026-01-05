#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Prototypes des fonctions */
char **split_line(char *line);
/* Note : execute_command sera ajouté plus tard */

#endif
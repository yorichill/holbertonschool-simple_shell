#include "shell.h"

/**
 * execute_command - Crée un processus enfant et exécute
 * @args: Tableau d'arguments
 * @prog_name: Nom du programme (argv[0]) pour les erreurs
 */
void execute_command(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		return;
	}
	if (child_pid == 0)
	{
		/* Exécution avec l'environnement global (environ) */
		if (execve(args[0], args, environ) == -1)
		{
			/* Format d'erreur strict : prog: line_num: cmd: not found */
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
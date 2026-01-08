#include "shell.h"

/**
 * execute_command - Exécute une commande via fork et execve
 * @args: Tableau d'arguments
 * @env: Environnement
 * @prog_name: Nom du programme pour les erreurs
 */
void execute_command(char **args, char **env, char *prog_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
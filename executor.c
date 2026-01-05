#include "shell.h"

/**
 * execute_command - Crée un processus et exécute une commande
 * @args: Tableau d'arguments
 * @env: Variables d'environnement
 */
void execute_command(char **args, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
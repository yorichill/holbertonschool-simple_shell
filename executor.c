#include "shell.h"

/**
 * execute_command - Executes a command with PATH management
 * @args: Array of arguments
 * @prog_name: Name of the shell for errors
 */
void execute_command(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;
	char *full_path;

	/* Recherche du chemin avant de créer un processus */
	full_path = get_path(args[0]);

	if (full_path == NULL)
	{
		/* Si non trouvé, erreur et PAS de fork */
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		free(full_path);
		return;
	}

	if (child_pid == 0)
	{
		/* Utilisation du chemin complet trouvé par get_path */
		if (execve(full_path, args, environ) == -1)
		{
			perror("Error");
			free(full_path);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		free(full_path);
	}
}

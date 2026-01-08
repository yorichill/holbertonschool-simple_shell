#include "shell.h"

/**
 * execute_command - Crée un processus enfant et exécute une commande
 * @args: Tableau d'arguments (ex: {"/bin/ls", "-l", NULL})
 * @prog_name: Nom du shell (argv[0]) pour l'affichage des erreurs
 *
 * Description : Cette fonction utilise fork pour dupliquer le processus.
 * L'enfant tente d'exécuter la commande avec execve. Si execve échoue,
 * un message d'erreur spécifique est affiché et l'enfant sort avec le
 * code 127.
 */
void execute_command(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork(); /* Création du processus enfant */
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}

	if (child_pid == 0) /* Code exécuté par l'enfant */
	{
		/* Utilisation de la variable globale environ */
		if (execve(args[0], args, environ) == -1)
		{
			/* Format d'erreur exact : ./hsh: 1: qwerty: not found */
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
			exit(127); /* Code de sortie requis par le shell */
		}
	}
	else /* Code exécuté par le parent */
	{
		/* Le parent attend que l'enfant termine son exécution */
		wait(&status);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * Note: environ est une variable globale externe fournie par le système.
 * Elle est nécessaire pour execve.
 */
extern char **environ;

/**
 * main - Simple Shell 0.1
 *
 * Description:
 * 1. Affiche un prompt "#cisfun$ ".
 * 2. Lit la commande de l'utilisateur (getline).
 * 3. Fork un processus enfant.
 * 4. L'enfant exécute la commande (execve).
 * 5. Le parent attend la fin de l'enfant (wait).
 * 6. Gère EOF (Ctrl+D) et les erreurs.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;
	char *argv[] = {NULL, NULL};

	while (1)
	{
		/* 1. Afficher le prompt seulement si on est en mode interactif */
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		/* 2. Lire la ligne de commande */
		nread = getline(&buffer, &len, stdin);

		/* Gestion de EOF (Ctrl+D) ou erreur de getline */
		if (nread == -1)
		{
			free(buffer);
			/* Si on est en interactif, on ajoute un saut de ligne esthétique */
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(EXIT_SUCCESS);
		}

		/* Suppression du retour à la ligne (\n) capturé par getline */
		if (buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		/* Si la ligne est vide (juste Entrée), on continue */
		if (strlen(buffer) == 0)
			continue;

		/* 3. Création du processus enfant */
		pid = fork();
		if (pid == -1)
		{
			perror("Error fork");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			/* --- PROCESSUS ENFANT --- */
			/* On prépare les arguments pour execve (ici pas d'arguments) */
			argv[0] = buffer;

			/* Exécution de la commande */
			/* Note: buffer doit être un chemin absolu (ex: /bin/ls) car pas de PATH */
			if (execve(argv[0], argv, environ) == -1)
			{
				/* Format d'erreur demandé : ./shell: No such file or directory */
				perror("./shell");
			}
			/* Si execve échoue, l'enfant doit mourir pour ne pas continuer la boucle */
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else
		{
			/* --- PROCESSUS PARENT --- */
			wait(&status);
		}
	}
	
	/* Nettoyage final (théoriquement inatteignable à cause du while(1)) */
	free(buffer);
	return (0);
}

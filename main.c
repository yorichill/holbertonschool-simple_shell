#include "shell.h"

/**
 * main - Point d'entrée du shell simple
 * @ac: Nombre d'arguments (non utilisé)
 * @av: Vecteur d'arguments (av[0] est le nom du programme)
 * Return: 0 en cas de succès
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	(void)ac;

	while (1)
	{
		/* Affiche le prompt ($) uniquement en mode interactif */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Gestion de Ctrl+D (EOF) */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* Suppression du saut de ligne final pour execve */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args = split_line(line);
		if (args && args[0])
		{
			/* Appel de l'exécuteur avec le nom du programme pour les erreurs */
			execute_command(args, av[0]);
		}

		free(args);
	}
	free(line);
	return (0);
}

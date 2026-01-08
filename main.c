#include "shell.h"

/**
 * main - Simple shell entry point
 * @ac: Number of arguments (not used)
 * @av: Argument vector (av[0] is the programme name)
 * Return: 0 if successful
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
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
        		exit(0); /* Quitte le shell proprement */
			}
			/* Appel de l'exécuteur avec le nom du programme pour les erreurs */
			execute_command(args, av[0]);
		}

		free(args);
	}
	free(line);
	return (0);
}

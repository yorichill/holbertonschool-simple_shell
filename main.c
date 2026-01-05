#include "shell.h"

/**
 * main - Boucle principale du shell
 * @ac: Nombre d'arguments
 * @av: Tableau d'arguments
 * @env: Environnement
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args = split_line(line);
		if (args && args[0])
			execute_command(args, env);

		free(args);
	}
	free(line);
	return (0);
}
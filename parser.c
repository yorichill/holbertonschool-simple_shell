#include "shell.h"

/**
 * split_line - Découpe une chaîne en tokens
 * @line: La ligne à traiter
 * Return: Tableau de chaînes
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}
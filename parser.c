#include "shell.h"

/**
 * split_line - Découpe une chaîne en jetons (tokens)
 * @line: La chaîne à découper
 * Return: Tableau de pointeurs vers les jetons
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
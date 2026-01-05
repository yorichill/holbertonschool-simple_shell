#include "shell.h"

/**
 * split_line - Découpe une chaîne en jetons
 * @line: La chaîne à découper
 * Return: Tableau de pointeurs vers les jetons
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens;
	char *token;
	char *delimiters = " \t\r\n\a";

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, delimiters);
	}
	tokens[position] = NULL;
	return (tokens);
}
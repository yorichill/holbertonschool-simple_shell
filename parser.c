#include "shell.h"

/**
 * split_line - Splits a string into tokens
 * @line: The string to be split
 * Return: Array of pointers to the tokens
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

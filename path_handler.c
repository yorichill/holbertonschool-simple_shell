#include "shell.h"

/**
 * get_path - Searches for the executable in the PATH directories
 * @command: Command name (e.g. ‘ls’)
 * Return: Full path (e.g. ‘/bin/ls’) or NULL if not found
 */
char *get_path(char *command)
{
	char *path, *path_copy, *token, *file_path;
	struct stat buffer;
	int i = 0;

	if (stat(command, &buffer) == 0)
		return (strdup(command));

	path = NULL;
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		file_path = malloc(strlen(token) + strlen(command) + 2);
		sprintf(file_path, "%s/%s", token, command);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

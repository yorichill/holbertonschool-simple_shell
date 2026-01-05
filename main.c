#include "shell.h"

/**
 * main - Point d'entrée du shell simple
 * @ac: Nombre d'arguments (non utilisé)
 * @av: Vecteur d'arguments (non utilisé)
 * @env: Environnement
 * Return: 0 en cas de succès
 */
int main(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;
    int i;
    (void)ac; (void)av; (void)env;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Gestion de Ctrl+D */
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        args = split_line(line);

        /* --- PETITE BOUCLE DE TEST --- */
        if (args)
        {
            for (i = 0; args[i] != NULL; i++)
            {
                printf("Argument [%d] : %s\n", i, args[i]);
            }
        }
        /* ----------------------------- */

        free(args);
    }
    free(line);
    return (0);
}
# C - Simple Shell (hsh)

## À propos du projet
#### Projet Simple Shell
Ce projet est une version simplifiée du shell Linux, développée dans le cadre d'un projet de groupe à Holberton School.

## Objectif
L'objectif est de créer un interpréteur de commandes capable d'exécuter des commandes simples, de gérer la variable d'environnement PATH et d'inclure des commandes internes (built-ins).

## Qu'est-ce que le shell ?
Le **shell** est un programme qui prend les commandes saisies au clavier via le terminal et les transmet au système d'exploitation pour exécution.

# Prérequis
- **GCC** (Standard de langage **gnu89**)
- **Ubuntu 20.04 LTS**
- Compréhension de base du langage C et des appels système Unix.

# INSTALLATION & UTILISATION
### Installation
**Étape 1 :** Clonez le dépôt
```bash
$ git clone [https://github.com/votre_depot/holbertonschool-simple_shell.git](https://github.com/votre_depot/holbertonschool-simple_shell.git)

```

**Étape 2 :** Accédez au répertoire :

```bash
$ cd holbertonschool-simple_shell

```

# Compilation

Le shell est compilé avec la commande suivante :

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

### Exécution

**Mode Interactif :**

```bash
$ ./hsh
($) /bin/ls
($) ls

```

**Mode Non-Interactif :**

```bash
$ echo "ls" | ./hsh

```

### Quitter le shell

* Tapez la commande `exit`
* Appuyez sur **Ctrl+D** (EOF)

# Liste des Fichiers

| Nom du fichier | Description |
| --- | --- |
| [main.c](https://www.google.com/search?q=main.c) | Point d'entrée, boucle REPL et gestion de l'interactivité. |
| [parser.c](https://www.google.com/search?q=parser.c) | Découpage de la ligne de saisie en jetons (tokens). |
| [path_handler.c](https://www.google.com/search?q=path_handler.c) | Recherche de la commande dans les répertoires du PATH. |
| [executor.c](https://www.google.com/search?q=executor.c) | Gestion du fork, de l'exécution (execve) et du wait. |
| [shell.h](https://www.google.com/search?q=shell.h) | Fichier d'en-tête contenant les prototypes et structures. |

## Fonctions et appels système utilisés

* `execve`, `fork`, `wait`, `stat`, `isatty`, `getline`, `strtok`, `malloc`, `free`, `fprintf`, `write`.

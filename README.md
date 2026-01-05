# Simple Shell - Holberton School Project

## Description
Ce projet consiste en la création d'un interpréteur de ligne de commande (Shell) simplifié, basé sur le fonctionnement du Thompson Shell. Il a été réalisé dans le cadre du cursus Holberton School pour comprendre la gestion des processus, les appels système et la manipulation de l'entrée standard.

## Fonctionnalités
- Affichage d'un prompt `($) ` en mode interactif.
- Exécution de commandes simples avec leurs arguments (ex: `/bin/ls -l`).
- Gestion de l'entrée standard (stdin) via `getline`.
- Gestion du mode interactif et non-interactif.
- Gestion du signal `EOF` (Ctrl+D) pour quitter le shell.

## Installation
Clonez le dépôt et compilez les fichiers `.c` :
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Utilisation
Mode interactif
Lancez le programme :
./hsh
($) /bin/ls
main.c parser.c executor.c shell.h hsh
($) exit
Mode non-interactif

Envoyez une commande via un pipe :

Bash

echo "/bin/ls" | ./hsh
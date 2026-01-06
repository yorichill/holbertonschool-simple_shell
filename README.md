# Simple Shell

Il s'agit d'un interpréteur de commandes UNIX simple écrit en langage C. Ce projet est une étape fondamentale pour comprendre le fonctionnement des processus, des appels système (system calls), de la gestion de mémoire et de l'environnement sous Linux.

Ce shell a été conçu pour imiter les fonctionnalités de base du **Bourne Shell (`sh`)**.

## 📋 Prérequis

* **Système d'exploitation :** Ubuntu 20.04 LTS
* **Compilateur :** GCC avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Style de code :** Betty Style

## 🛠 Installation et Compilation

Clonez ce dépôt sur votre machine locale, puis compilez le programme en utilisant la commande suivante :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

🚀 Utilisation

Le shell fonctionne en deux modes : interactif et non-interactif.
1. Mode Interactif

Lancez le programme et attendez le prompt ($).
Bash

./hsh
($) /bin/ls
hsh main.c shell.c
($) exit

2. Mode Non-interactif

Vous pouvez envoyer des commandes via un pipe ou un fichier.
Bash

echo "/bin/ls" | ./hsh
hsh main.c shell.c

✨ Fonctionnalités

    Exécution de commandes : Exécute des programmes situés dans le système (ex: /bin/ls) ou dans le répertoire courant.

    Gestion du PATH : Cherche les exécutables dans les répertoires définis par la variable d'environnement PATH.

    Gestion des erreurs : Affiche des messages d'erreur identiques à sh en cas de commande introuvable ou d'erreur d'exécution.

    Gestion de l'environnement : Hérite de l'environnement du processus parent.

    Fin de fichier (EOF) : Gère Ctrl+D pour quitter proprement.

Commandes intégrées (Built-ins)

    exit : Quitte le shell.

    env : Affiche l'environnement actuel.

📝 Exemples
Succès
Bash

julien@ubuntu:/# ./hsh
($) ls -l
total 20
-rwxr-xr-x 1 user user 18000 Jan 1 12:00 hsh
-rw-r--r-- 1 user user   500 Jan 1 12:00 main.c
($)

Gestion d'erreur

Le format d'erreur respecte la syntaxe : Nom_du_programme: Ligne: Commande: not found
Bash

julien@ubuntu:/# echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found

📂 Structure des Fichiers

    AUTHORS : Liste des contributeurs au projet.

    man_1_simple_shell : Page de manuel du shell.

    shell.h : Fichier d'en-tête contenant les prototypes et structures.

    *.c : Fichiers sources contenant l'implémentation (main, parsing, execution, built-ins, etc.).

📚 Ressources

    Unix shell (Wikipedia)

    Thompson shell (Wikipedia)

    Man pages (sh, execve, fork, wait, etc.)

👥 Auteurs

    Thomas Haenel

    Thélyaan Dufrénoy
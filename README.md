### 1. `README.md`

```markdown
# C - Simple Shell (hsh)

## About the project
#### Simple Shell Project
This project is a simplified version of the Linux shell, developed as part of a group project at Holberton School.

## Objective
The goal is to create a command line interpreter capable of executing simple commands, managing the PATH environment variable, and including built-in commands.

## What is the shell?
The **shell** is a program that takes commands entered from the keyboard via the terminal and passes them to the operating system for execution.

# Prerequisites
- **GCC** (Language standard **gnu89**)
- **Ubuntu 20.04 LTS**
- Basic understanding of C language and Unix system calls.

# INSTALLATION & USAGE
### Installation
**Step 1:** Clone the repository
```bash
$ git clone (https://github.com/your_repo/holbertonschool-simple_shell.git)

```

**Step 2:** Navigate to the directory:

```bash
$ cd holbertonschool-simple_shell

```

# Compilation

The shell is compiled using the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

### Execution

**Interactive Mode:**

```bash
$ ./hsh
($) /bin/ls
($) ls

```

**Non-Interactive Mode:**

```bash
$ echo "ls" | ./hsh

```

### Exiting the shell

* Type the command `exit`
* Press **Ctrl+D** (EOF)

# File List

| File Name | Description |
| --- | --- |
| [main.c](https://www.google.com/search?q=main.c) | Entry point, REPL loop, and interactivity management. |
| [parser.c](https://www.google.com/search?q=parser.c) | Tokenization of the input line into separate arguments. |
| [path_handler.c](https://www.google.com/search?q=path_handler.c) | Command lookup within the PATH environment variable directories. |
| [executor.c](https://www.google.com/search?q=executor.c) | Management of fork, execution (execve), and process waiting. |
| [shell.h](https://www.google.com/search?q=shell.h) | Header file containing prototypes and structures. |

## Flowchart

![Flowchart du Shell](./flowchartv2.png)

## Functions and System Calls Used

* `execve`, `fork`, `wait`, `stat`, `isatty`, `getline`, `strtok`, `malloc`, `free`, `fprintf`, `write`.

```

---

### 2. `man_1_simple_shell` (English Version)

```roff
.TH HSH 1 "May 2024" "1.0" "Simple Shell Manual"
.SH NAME
.B hsh
- Simplified UNIX command interpreter

.SH SYNOPSIS
.B Interactive mode:
.RS
./hsh
.RE
.B Non-interactive mode:
.RS
echo "[COMMAND]" | ./hsh
.RE

.SH DESCRIPTION
.B hsh
[cite_start]is a command-line interpreter that reads instructions from standard input or a pipe. [cite: 5, 6] [cite_start]It searches for commands in the current PATH, executes them in a child process, and waits for their completion. [cite: 7]

.SH BUILT-IN COMMANDS
.B hsh
[cite_start]supports the following built-in commands: [cite: 8]
.sp
.B exit
.RS
[cite_start]Exits the shell cleanly with an exit status of 0. [cite: 8]
.RE
.B env
.RS
[cite_start]Prints all current environment variables. [cite: 8, 9]
.RE

.SH PATH SEARCH
[cite_start]If a command does not contain a forward slash (/), the shell searches for the executable in the directories listed in the PATH environment variable. [cite: 9] [cite_start]If the command is not found, an error message is printed to the standard error output (stderr). [cite: 10]

.SH EXIT STATUS
[cite_start]Returns 0 upon success, and 127 if a command is not found. [cite: 11]

.SH SEE ALSO
[cite_start].I sh(1), bash(1) [cite: 12]

.SH AUTHORS
Thomas <your_email>
Project developed as part of the Holberton School curriculum.

```
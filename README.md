# Minishell

A simple Unix shell implemented in C.

Project Description
Minishell is a command-line shell that allows users to execute commands, handle built-ins, manage environment variables, perform input/output redirection, and use pipes for communication between processes.

How It Works

* The shell waits for user input and parses it into commands.
* Built-in commands like `cd`, `echo`, `export`, `unset`, `exit`, and `pwd` are executed internally.
* For other commands, the shell creates a child process using `fork()` and executes the command using `execve()`.
* Supports input/output redirection (`>`, `<`, `>>`) and pipes (`|`).
* Handles basic signals (`CTRL+C` to interrupt, `CTRL+D` to exit).

Features

* Execute system commands with arguments.
* Built-in commands executed without spawning new processes.
* Input and output redirection.
* Pipes connecting multiple commands.
* Environment variable management.
* Basic signal handling.

## Usage

### 1. Compile the project

```bash
make
```

### 2. Start the shell

```bash
./minishell
```

### 3. Run commands

* **External commands:**

```bash
ls
pwd
echo Hello World
```

* **Built-in commands:**

```bash
cd /path/to/directory
export VAR=value
unset VAR
exit
```

* **Pipes and redirection:**

```bash
ls -l | grep ".c" > files.txt
cat < files.txt
```

### Files

main.c - Entry point and main loop of the shell.

builtins.c - Implementation of built-in commands.

parser.c - Parses input commands and splits them into executable parts.

executor.c - Executes commands and manages child processes.

utils.c - Helper functions.

minishell.h - Header file with function prototypes and definitions.

Makefile - Compiles the project.

Notes

* The shell must be running to execute commands.
* Signal handling prevents crashing when interrupting commands.
* Supports standard ASCII input.

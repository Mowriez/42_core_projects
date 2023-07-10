# Minishell (group project with @eramusho)

# Project Overview
The Minishell project involves creating a functional command-line interpreter, 
similar to the well-known Unix shell, such as Bash or Zsh. It provides users 
with a command prompt where they can interact with the operating system by executing
various commands.

# Key Features
The Minishell project encompasses the following key features:

Command Execution: Minishell allows users to execute a wide range of commands available 
in their Unix environment. This includes both built-in commands (e.g., cd, echo, env, etc.)
and external commands (e.g., ls, grep, etc.).

Path Resolution: Minishell is responsible for searching and resolving the correct paths
for executing commands. It utilizes the PATH environment variable to locate the 
appropriate executable files.

Redirection and Pipes: Minishell supports input/output redirection and 
piping of commands. This allows users to redirect standard input/output to/from files 
and connect multiple commands together using pipes.

Signal Handling: The shell is designed to handle various signals, such as Ctrl+C (SIGINT) 
and Ctrl+\ (SIGQUIT), providing proper termination and handling of processes.

Environment Variables: Minishell manages environment variables, allowing users 
to view, modify, and set new variables within the shell.

# Getting Started
To get started with this Minishell, follow these steps:

Clone the repository to your local machine.
Compile the source code using the provided makefile. You could also potentially need to
fetch the "readline"-library which is used to get user input on runtime. For this it would
be neccessary to change the path to the library to your personal file structure in the
projects' Makefile.
Run the resulting executable to start the Minishell program.
Use the command prompt to execute various commands and explore the shell's functionalities.

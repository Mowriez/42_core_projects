# Minishell
> A simple shell implementation in C.

# Overview
The Minishell project involves creating a command-line interpreter, 
similar to the well-known Unix shell. It provides users 
with a command prompt where they can interact with the operating system by executing various commands.

# Description

## Features
- **Command Execution**: Execute a wide range of commands available in their Unix environment. This includes both built-in commands (e.g., cd, echo, env, etc.) and external commands (e.g., ls, grep, etc.).
- **Path Resolution**: Searching and resolving the correct paths for executing commands. Utilizes the PATH environment variable to locate the appropriate executable files.
- **Redirection and Pipes**: Supports input/output redirection and piping of commands. This allows users to redirect standard input/output to/from files and connect multiple commands together using pipes.
- **Signal Handling**: Handles various signals, such as Ctrl+C (SIGINT) and Ctrl+\ (SIGQUIT), providing proper termination and handling of processes.
- **Environment Variables**: Manages environment variables, allowing users to view, modify, and set new variables within the shell.

## Build and run the project
To get started with this Minishell, follow these steps:

1. Clone the repository and compile it with 'make'. <br>

2. Run the following command from the terminal to start the Minishell program:

        ./minishell

3. You possibly need to fetch the "readline"-library which is used to get user input on runtime. Install with (Linux environment):

        sudo apt update
        sudo apt install libreadline-dev


4. Run the resulting executable to start the Minishell program.

        ./minishell

5. Use the command prompt to execute various commands and explore functionalities of the Minishell.

### built by @eramusho & @mtrautne

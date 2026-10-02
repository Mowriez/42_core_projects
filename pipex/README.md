# Pipex
> Piping and executing commands in a shell-like manner.

# Overview
The Pipex project involves creating a command-line program that mimics the behavior of the shell pipe operator (|). It takes two commands and redirects the output of the first command as the input of the second command, emulating the behavior of the shell's pipe operator.

# Description
## Features
- **Command Execution**: Pipex allows users to execute two commands, just like in a shell pipeline. It handles the execution of the commands in correct order.
- **Input/Output Redirection**: As the original pipe operator does, Pipex redirects the output of the first command to the input of the second command. It also supports input and output redirection from/to files.
- **File Creation and Permissions**: The program handles the creation of output files and sets the appropriate permissions for the newly created files.
- **Error Handling**: Pipex provides error handling mechanisms for various scenarios, such as invalid commands, file-related errors, and failures during command execution.

## Build and run the project

1. Clone the repository and compile it with 'make'.

2. Run the following command from the terminal to start the program, providing the appropriate command-line arguments for input and output files, as well as the two commands to execute:

        ./pipex <input_file> <command1> <command2> <output_file>

3. Find the output of your command in the specified output file.

# Get Next Line
> Memory allocation and file I/O in C.
## Overview
This project is about setting up a function which reads input from a file descriptor and handles heap memory allocation in C. 

# Description

## Features

- **Chunking**: Reads input in chunks of a specified buffer size.
- **Dynamic Memory Allocation**: Dynamically allocates and frees memory to store the chunks without memory leaks.
- **Secure returns**: Returns a line as soon as a newline character is found.

## Dependencies

- Linux or macOS environment

## Build and run the project

1. Clone the repository and navigate to the project directory.

2. Use the function `get_next_line` in your C code to read lines from a file descriptor. Make sure to include the header file `get_next_line.h` in your source files.

3. Repeatedly call `get_next_line` to read lines from the file descriptor until it returns NULL, indicating the end of the file or an error.

4. It's still only a function and no program, you can test it by creating a simple C program that opens a file and uses `get_next_line` to read its contents line by line.
# PushSwap
> Y'all got any more of them sorting algorithms?

# Overview
The push_swap project sorts a stack of integers using a limited set of operations. The goal is to sort the stack in ascending order with the least number of operations possible. The project involves creating a program that takes an unsorted stack of integers as input and outputs a series of instructions that, when executed, will sort the stack.

# Description
## Features

- **Stack Operations**: The program implements a set of stack operations, including push, swap, rotate, and reverse rotate, to manipulate the stack of integers.<br>
- **Sorting Algorithm**: The program uses a proprietary algorithm to sort stacks of up to 5 elements and the radix sort algorithm for larger stacks.<br>
- **Input Validation**: The program checks for valid input, ensuring that the provided integers are within the acceptable range and that there are no duplicates.<br>
- **Output Instructions**: The program outputs a series of instructions that, when executed, will sort the stack in ascending order.

## Build and run the project

1. Clone the repository and compile it with 'make'.

2. Run the following command from the terminal to start the program, specifying the unsorted stack of integers as input:

        ./push_swap <integer1> <integer2> <integer3> ...

3. The program will output a series of instructions that, when executed, will sort the stack in ascending order.

4. Validating the output was done by an internal checker program. If you don't have access to 42 intra, you can check small stacks by hand.

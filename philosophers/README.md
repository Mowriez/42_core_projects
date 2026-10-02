# Philosophers
> Let them eat spaghetti!

# Overview
The Philosophers project involves creating a program that simulates the dining philosophers problem. The goal is to design a solution that allows the philosophers to alternate between thinking and eating while avoiding deadlocks and resource starvation.

# Description
## Features

- **Concurrency Management**: The program manages multiple philosophers as separate threads. It handles thread creation, synchronization, and communication.
- **Resource Allocation**: The philosophers compete for limited resources (forks). They must acquire the necessary forks to eat and release them promptly when finished to allow other philosophers to use them.
- **Deadlock Avoidance**: The program implements a solution to avoid deadlocks, assuring all threads can access the resources they need in due time without getting stuck in a circular wait.


## Build and run the project

1. Clone the repository and compile it with 'make'.

2. Run the following command from the terminal to start the program, specifying the number of philosophers and any other necessary parameters:

        ./philo <number_of_philosophers> <time_to_death> <time_for_eating> <time_asleep> [number_of_times_each_philosopher_must_eat]

    The last parameter is optional. If not provided, the philosophers will continue to eat indefinitely.

3. Observe the output in the terminal, which will display the actions of each philosopher as they think, eat, and sleep.

4. If you wish to stop the program, you can use the keyboard interrupt (Ctrl+C) to terminate it.

> Depending on your input parameters, it might be impossible for all philosophers to eat (all threads to access resources in time). The program will terminate if a philosopher dies due to starvation, and the output will indicate which philosopher has died. 

> If you get close to the theoretical limit of a successful run, you might see philosophers dying due to starvation even if the input parameters should allow them to survive. This is expected behavior and demonstrates the challenges of resource allocation in concurrent systems - basically your cpu is not keeping up with the theoretically possible limits of your input parameters.

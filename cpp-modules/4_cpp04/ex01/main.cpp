/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:49:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:13:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	
	std::cout << std::endl << GRE "####-----CREATING ARRAY-----####" RES << std::endl;
	Animal* array[5];
	for (int i = 0; i < 6; i++) {
		std::cout << std::endl << YEL "ANIMAL " << i << ":" RES << std::endl;
		if ((i % 2) == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		std::cout << "Idea: " << array[i]->getIdea(0) << std::endl;
		std::cout << "Sound: ";
		array[i]->makeSound();
	}

	std::cout << std::endl << GRE "####-----DELETING ARRAY-----####" RES << std::endl;
	for (int i = 0; i < 6; i++) {
		delete array[i];
	}
	
	std::cout << std::endl << GRE "####-----DEEP COPY/ASSIGNMENT-----####" RES << std::endl;
	Dog basic;
	std::cout << YEL "basic constructed" RES << std::endl << std::endl;
	{
		Dog temp = basic;
		std::cout << PUR "temp idea: " RES << temp.getIdea(0) << std::endl;
		std::cout << YEL "temp constructed, end of scope for temp" RES << std::endl << std::endl;
	}
	std::cout << PUR "basic idea: " RES << basic.getIdea(0) << std::endl;
	std::cout << YEL "end of scope for basic" RES << std::endl << std::endl;
	return (0);
}

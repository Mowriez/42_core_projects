/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:49:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:16:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	
	std::cout << std::endl << GRE "####-----CREATING ABSTRACT CLASS OBJECT-----####" RES << std::endl;
	// Animal test;

	std::cout << std::endl << GRE "####-----NORMAL FUNCTION OF DERIVED CLASSES-----####" RES << std::endl;
	std::cout << BLU "####-----constructors-----####" RES << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << BLU "####-----assignments / types-----####" RES << std::endl;
	std::cout << "j " << j->getType()  << " | Idea: " << j->getIdea(0) << std::endl;
	std::cout << "i " << i->getType()  << " | Idea: " << i->getIdea(0) << std::endl;

	std::cout << std::endl << BLU "####-----polymorphism check/ virtual member fct-----####" RES << std::endl;
	j->makeSound();
	i->makeSound();

	std::cout << std::endl << BLU "####-----destructors-----####" RES << std::endl;
	delete j;
	delete i;
	return (0);
}

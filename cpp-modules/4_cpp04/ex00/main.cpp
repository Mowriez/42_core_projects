/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:49:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 12:33:05 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

	std::cout << std::endl << GRE "####-----CORRECT IMPLEMENTATION-----####" RES << std::endl;
	std::cout << std::endl << BLU "####-----constructors-----####" RES << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << BLU "####-----assignments / types-----####" RES << std::endl;
	std::cout << "j " << j->getType() << " " << std::endl;
	std::cout << "i " << i->getType() << " " << std::endl;

	std::cout << std::endl << BLU "####-----polymorphism check/ virtual member fct-----####" RES << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	std::cout << std::endl << BLU "####-----destructors-----####" RES << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << RED "####-----BAD IMPLEMENTATION-----####" RES << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl << BLU "####-----assignment / type-----####" RES << std::endl;
	std::cout << "k " << k->getType() << " " << std::endl;

	std::cout << std::endl << BLU "####-----polymorphism check/" << 
	"NON!-virtual member fct-----####" RES << std::endl;
	k->makeSound();
	meta2->makeSound();

	std::cout << std::endl << BLU "####-----destructors-----####" RES << std::endl;
	delete meta2;
	delete k;

	return (0);
}

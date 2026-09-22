/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 21:58:21 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_Brain->setIdea(i, "Thanks for all the fish!");
	}
}

Cat::Cat(const Cat& original) : Animal() {
	std::cout << "Cat copy constructor called." << std::endl;
	this->_Brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_Brain->setIdea(i, original.getIdea(i));
	}
	this->_type = original._type;
}

Cat&	Cat::operator=(const Cat& original) {
	std::cout << "Cat assignment operator overload called." << std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	for (int i = 0; i < 100; i++) {
		this->_Brain->setIdea(i, original.getIdea(i));
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete this->_Brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow meow!" << std::endl;
}

std::string	Cat::getIdea(int i) const {
	if (i < 0 || i >= 100)
		return ("");
	return (this->_Brain->getIdea(i));
}

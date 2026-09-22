/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:34:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:01:52 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_Brain->setIdea(i, "Squirrel ?!");
	}
}

Dog::Dog(const Dog& original) : Animal() {
	std::cout << "Dog copy constructor called." << std::endl;
	this->_type = original._type;
	this->_Brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_Brain->setIdea(i, original.getIdea(i));
	}
}

Dog&	Dog::operator=(const Dog& original) {
	std::cout << "Dog assignment operator overload called." << std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	for (int i = 0; i < 100; i++) {
		this->_Brain->setIdea(i, original.getIdea(i));
	}
	return (*this);
	}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete this->_Brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}

std::string	Dog::getIdea(int i) const {
	if (i < 0 || i >= 100)
		return ("");
	return (this->_Brain->getIdea(i));
}


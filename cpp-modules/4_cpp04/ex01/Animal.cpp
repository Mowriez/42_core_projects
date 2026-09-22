/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:34:29 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:12:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& original) {
	std::cout << "Animal copy constructor called." << std::endl;
	this->_type = original._type;
}

Animal&	Animal::operator=(const Animal& original) {
	std::cout << "Animal assignment operator overload called." << std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Random animal noises..." << std::endl;
}

std::string	Animal::getType() const {
	return("Object type: " + this->_type);
}

std::string		Animal::getIdea(int i) const {
	i++;
	return ("I have no brain...");
}

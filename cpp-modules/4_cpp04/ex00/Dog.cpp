/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:34:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:10:08 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& original) : Animal() {
	std::cout << "Dog copy constructor called." << std::endl;
	this->_type = original._type;
}

Dog&	Dog::operator=(const Dog& original) {
	std::cout << "Dog assignment operator overload called." << std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
	}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}

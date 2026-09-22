/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:09:55 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& original) : Animal() {
	std::cout << "Cat copy constructor called." << std::endl;
	this->_type = original._type;
}

Cat&	Cat::operator=(const Cat& original) {
	std::cout << "Cat assignment operator overload called." << std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow meow!" << std::endl;
}

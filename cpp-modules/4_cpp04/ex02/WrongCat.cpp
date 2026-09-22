/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:31:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/24 18:20:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called." << std::endl;
	this->_type = original._type;
}

WrongCat&	WrongCat::operator=(const WrongCat& original) {
	std::cout << "WrongCat assignment operator overload called." << std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Weom weom!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:18:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/16 22:02:38 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed:: _fract_bits_num = 8;

Fixed::Fixed() : _value(0) {
	std::cout << BLUE "Default constructor called." RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED "Destructor called." RESET << std::endl;
}

// could also write this as *this = original. In this case "=" is the assignment operator which
//copies the values as defined in the copy assignment operator overload fct below.
Fixed::Fixed(const Fixed& original) {
	std::cout << YELLOW "Copy constructor called" << RESET << std::endl;
	this->_value = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original) {
	std::cout << GREEN "Copy assignment operator called" << RESET << std::endl;
	if (this == &original) //self assignment scenario -> just returns a reference to itself;
		return (*this);
	this->_value = original.getRawBits();	// initialises value to og value. Shallow copy suffices here as
											//there is no dynamically allocated memory.
	return (*this);
}

// const keyword indicates that the member function getRawBits() is a const member function.
// When a member function is declared as const, it means that the function does not modify 
// the state of the object on which it is called. Within a const member function, you 
// cannot modify any non-static member variables of the class unless they are declared 
// as mutable.

int Fixed::getRawBits() const {
	std::cout << PURPLE "getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << BLUE "setRawBits member function called" << RESET << std::endl;
	this->_value = raw;
}

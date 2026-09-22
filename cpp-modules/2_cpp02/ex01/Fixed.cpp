/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:18:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/19 10:37:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

const int Fixed:: _fract_bits_num = 8;

Fixed::Fixed() : _value(0) {
	std::cout << GREEN "Default constructor called." RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED "Destructor called." RESET << std::endl;
}

Fixed::Fixed(const Fixed& original) {
	std::cout << YELLOW "Copy constructor called" << RESET << std::endl;
	*this = original; //changed to represent the output wished for by the exercise.
}

Fixed& Fixed::operator=(const Fixed& original) {
	std::cout << BLUE "Copy assignment operator called" << RESET << std::endl;
	if (this == &original)
		return (*this);
	this->_value = original.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

// new stuff vs ex01

Fixed::Fixed(const int int_value) {
	std::cout << PURPLE "Int constructor called." RESET << std::endl;
	setRawBits(int_value << this->_fract_bits_num);
}

Fixed::Fixed(const float float_value) {
	std::cout << CYAN "Float constructor called." RESET << std::endl;
	setRawBits(roundf(float_value * (1 << _fract_bits_num)));
}

float	Fixed::toFloat(void) const {
	return ((float)(this->_value) / (float)(1 << this->_fract_bits_num));
}

int	Fixed::toInt(void) const {
	return this->_value >> this->_fract_bits_num;
}

std::ostream&	operator<<(std::ostream& ostream_obj, const Fixed& fixed) {
	ostream_obj << fixed.toFloat();
	return (ostream_obj);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:18:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/19 11:16:52 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

const int Fixed:: _fract_bits_num = 8;

Fixed::Fixed() : _value(0) {
	// std::cout << GREEN "Default constructor called." RESET << std::endl;
}

Fixed::~Fixed() {
	// std::cout << RED "Destructor called." RESET << std::endl;
}

Fixed::Fixed(const Fixed& original) {
	// std::cout << YELLOW "Copy constructor called" << RESET << std::endl;
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original) {
	// std::cout << BLUE "Copy assignment operator called" << RESET << std::endl;
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

Fixed::Fixed(const int int_value) {
	// std::cout << PURPLE "Int constructor called." RESET << std::endl;
	setRawBits(int_value << this->_fract_bits_num);
}

Fixed::Fixed(const float float_value) {
	// std::cout << CYAN "Float constructor called." RESET << std::endl;
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

bool Fixed::operator>(Fixed const &fixed_2) {
	return ((this->getRawBits() > fixed_2.getRawBits()));
}

bool Fixed::operator<(Fixed const &fixed_2) {
	return ((this->getRawBits() < fixed_2.getRawBits()));
}

bool Fixed::operator>=(Fixed const &fixed_2) {
	return ((this->getRawBits() >= fixed_2.getRawBits()));
}

bool Fixed::operator<=(Fixed const &fixed_2) {
	return ((this->getRawBits() <= fixed_2.getRawBits()));
}

bool Fixed::operator!=(Fixed const &fixed_2) {
	return ((this->getRawBits() != fixed_2.getRawBits()));
}

bool Fixed::operator==(Fixed const &fixed_2) {
	return ((this->getRawBits() == fixed_2.getRawBits()));
}

Fixed Fixed::operator*(Fixed const &fixed_2) {
	Fixed result(this->toFloat() * fixed_2.toFloat());
	return result;
}

Fixed Fixed::operator+(Fixed const &fixed_2) {
	Fixed result(this->toFloat() + fixed_2.toFloat());
	return result;
}

Fixed Fixed::operator-(Fixed const &fixed_2){
	Fixed result(this->toFloat() - fixed_2.toFloat());
	return result;
}

Fixed Fixed::operator/(Fixed const &fixed_2){
	Fixed result(this->toFloat() / fixed_2.toFloat());
	return result;
}

Fixed& Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed result(*this);
	this->_value++;
	return result;
}

// Prefix decrement operator (--). decrement the value and return the modified object itself (by reference).
Fixed& Fixed::operator--(void) {
	this->_value--;
	return(*this);
}

// Postfix decrement operator (--). Decrement the value of the object but return the original (unmodified)
// object by value. In this case, a copy of the current object is made (Fixed result(*this)), then the 
// member variable _value is decremented, and finally, the copy of the original object (before decrement)
//  is returned.
Fixed Fixed::operator--(int) { //int = naming convention to differentiate from pre-decrement operator
	Fixed result(*this);
	this->_value--;
	return result;
}

Fixed&	Fixed::min(Fixed& fixed, Fixed& fixed_2) {
	return ((Fixed(fixed) < Fixed(fixed_2)) ? fixed : fixed_2);
}

const Fixed&	Fixed::min(Fixed const &fixed, Fixed const &fixed_2) {
	return ((Fixed(fixed) < Fixed(fixed_2)) ? fixed : fixed_2);
}

Fixed&	Fixed::max(Fixed& fixed, Fixed& fixed_2) {
	return ((Fixed(fixed) > Fixed(fixed_2)) ? fixed : fixed_2);
}

const Fixed&	Fixed::max(Fixed const &fixed, Fixed const &fixed_2) {
	return ((Fixed(fixed) > Fixed(fixed_2)) ? fixed : fixed_2);
}
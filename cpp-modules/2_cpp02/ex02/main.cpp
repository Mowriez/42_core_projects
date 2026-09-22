/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:31:24 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/19 11:34:54 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	{
	std::cout << "#####-----Requested in exercise-----#####" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;
	}
	{
	std::cout << BLUE "#####-----More awesome tests-----#####" RESET << std::endl;
	std::cout << GREEN "arithmetic operands" RESET << std::endl;
	Fixed a = -2.567f;
	std::cout << "a was initialised as -2.567f and is represented as: " << a << std::endl;
	Fixed b = 4;
	std::cout << "b was initialised as 4 and is represented as: " << b << std::endl;
	Fixed c (a * b);
	std::cout << "c was initialised as a * b and is represented as: " << c << std::endl;
	Fixed d (c / a);
	std::cout << "d was initialised as c / a and is represented as: " << d << std::endl;
	Fixed e (a + b);
	std::cout << "e was initialised as a + b and is represented as: " << e << std::endl;
	Fixed f (a - b);
	std::cout << "f was initialised as a - b and is represented as: " << f << std::endl;
	std::cout << GREEN "Pre-/ Post - Increment-/ Decrement- operators" RESET << std::endl;
	Fixed g = b++;
	std::cout << "g was initialised as b++ and is represented as: " << g << " but b is now : " << b << std::endl;
	Fixed h = ++b;
	std::cout << "h was initialised as ++b and is represented as: " << h << " (don't forget it was incremented before)" << std::endl;
	Fixed i = b--;
	std::cout << "i was initialised as b-- and is represented as: " << i << " but b is now : " << b << std::endl;
	Fixed j = --b;
	std::cout << "j was initialised as --b and is represented as: " << j << " (don't forget it was decremented before)" << std::endl;
	std::cout << GREEN "Min & Max" RESET << std::endl;
	std::cout << "The max between a (-2.567f) and b (4) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "The min between a (-2.567f) and b (4) = " << Fixed::min( a, b ) << std::endl;
	}
	return 0;
}

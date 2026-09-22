/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:31:49 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/16 22:04:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RED "\033[1;31m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class Fixed {
	private:
		int					_value;
		static const int	_fract_bits_num; 
		//initialising this variable in the class declaration would make it a compile 
		//time constant. Should suffice as all objects need this value to be 8. Still rather
		// init it in cpp file.

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& original); // copy constructor
		Fixed& operator=(const Fixed& original); // copy assignment operator

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

# endif

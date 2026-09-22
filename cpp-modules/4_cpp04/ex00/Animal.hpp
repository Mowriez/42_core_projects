/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:21:45 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 12:11:24 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

// colors
# define RED "\033[1;31m"
# define PUR "\033[1;35m"
# define YEL "\033[1;33m"
# define GRE "\033[1;32m"
# define BLU "\033[1;34m"
# define RES "\033[0m"

class Animal {
	protected:
		std::string		_type;

	public:
		Animal();
		Animal(const Animal& original);
		Animal&	operator=(const Animal& original);
		virtual ~Animal(); //compiler complains "possible undefined behaviour if non-virtual destructor"
		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif

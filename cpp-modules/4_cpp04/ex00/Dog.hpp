/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:23:32 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 12:03:43 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>

#ifndef	DOG_HPP
# define DOG_HPP

class Dog : public Animal{
	private:

	public:
		Dog();
		Dog(const Dog& original);
		Dog&	operator=(const Dog& original);
		~Dog();

		void	makeSound() const;
};

#endif

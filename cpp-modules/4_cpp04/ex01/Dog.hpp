/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:23:32 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 21:55:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <string>

#ifndef	DOG_HPP
# define DOG_HPP

class Dog : public Animal{
	private:
		Brain*	_Brain;
	public:
		Dog();
		Dog(const Dog& original);
		Dog&	operator=(const Dog& original);
		virtual ~Dog();

		void		makeSound() const;
		std::string	getIdea(int i) const;
};

#endif

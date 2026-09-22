/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:50:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 21:53:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

#ifndef	CAT_HPP
# define CAT_HPP

class Cat : public Animal{
	private:
		Brain*	_Brain;
	public:
		Cat();
		Cat(const Cat& original);
		Cat&	operator=(const Cat& original);
		virtual ~Cat();

		void		makeSound() const;
		std::string	getIdea(int i) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:50:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 12:03:47 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>

#ifndef	CAT_HPP
# define CAT_HPP

class Cat : public Animal{
	private:

	public:
		Cat();
		Cat(const Cat& original);
		Cat&	operator=(const Cat& original);
		~Cat();

		void	makeSound() const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:19:29 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 12:32:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

// colors
# define RED "\033[1;31m"
# define PUR "\033[1;35m"
# define YEL "\033[1;33m"
# define GRE "\033[1;32m"
# define BLU "\033[1;34m"
# define RES "\033[0m"

class WrongAnimal {
	protected:
		std::string		_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		WrongAnimal&	operator=(const WrongAnimal& original);
		~WrongAnimal();
		
		void		makeSound() const; // purposely wrong implementation!!
		std::string	getType() const;
};

#endif

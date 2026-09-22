/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:22:19 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 12:34:05 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>

#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat : public WrongAnimal{
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat& original);
		WrongCat&	operator=(const WrongCat& original);
		~WrongCat();

		void	makeSound() const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:10:49 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:42:00 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef WEAPON_HPP
# define WEAPON_HPP

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

class Weapon {

	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

	// The const qualifier ensures that the returned reference cannot be used
	// to modify the object it refers to.
	const std::string&	getType();
	void				setType(std::string type);
};

#endif

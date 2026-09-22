/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:12:29 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:41:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {

	private:
		Weapon		*equipped_weapon; //Weapon is a pointer here as reference cannot be null-initialised
		std::string	name;

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon& input_weapon);
};

#endif

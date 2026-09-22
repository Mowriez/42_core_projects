/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:31:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:41:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// HumanA::HumanA() {
// 	std::cout << this->name << " created" << std::endl;
// }

HumanA::HumanA(std::string name, Weapon& weapon)
	: weapon(weapon), name(name) {
	std::cout << GREEN << this->name << " created" << RESET << std::endl;
	}

HumanA::~HumanA() {
	std::cout << RED << this->name << " deleted" << RESET << std::endl;
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType()
	<< std::endl;
}

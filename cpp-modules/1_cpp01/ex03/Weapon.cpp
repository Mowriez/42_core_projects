/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:40:25 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:41:59 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() {
	std::cout << GREEN << "unknown weapon created." << RESET << std::endl;
}

Weapon::Weapon(std::string input_type)
	: type(input_type){
		std::cout << GREEN << input_type << " created." << RESET << std::endl;
	}

Weapon::~Weapon() {
	std::cout << RED << this->type << " deleted." << RESET << std::endl;
}

const std::string&	Weapon::getType() {
	std::string&	reference = this->type;
	return (reference);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:24:12 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/22 22:25:02 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {
	std::cout << GRE "DiamondTrap default constructor called" RES << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	ClapTrap::set_name(name + "_clap_name");
	this->_name = name;
	this->_h_pts = this->FragTrap::_h_pts;
	this->_e_pts = this->ScavTrap::_e_pts;
	this->_a_dmg = this->FragTrap::_a_dmg;
	std::cout << GRE "DiamondTrap constructor called" RES << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& original) : ClapTrap(), FragTrap(), ScavTrap() {
	std::cout << BLU << "DiamondTrap copy constructor called" RES << std::endl;
	*this = original;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& original) {
	std::cout << PUR "DiamondTrap copy assignment operator called" << RES << std::endl;
	if (this == &original)
		return (*this);
	this->ClapTrap::_name = original.ClapTrap::_name;
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << RED << "DiamondTrap default destructor called" RES << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->_name << ", my ClapTrap name is " 
	<< this->ClapTrap::get_name() << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
}

std::string		DiamondTrap::get_name() const {
	return (this->_name);
}

unsigned int	DiamondTrap::get_hit_points() const {
	return (this->_h_pts);
}

unsigned int	DiamondTrap::get_energy_points() const {
	return (this->_e_pts);
}

unsigned int	DiamondTrap::get_attack_damage() const {
	return (this->_a_dmg);
}
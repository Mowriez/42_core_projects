/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:01:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/22 20:19:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->_h_pts = 100;
	this->_e_pts = 50;
	this->_a_dmg = 20;
	std::cout << GRE << "ScavTrap default constructor called" RES << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_h_pts = 100;
	this->_e_pts = 50;
	this->_a_dmg = 20;
	std::cout << GRE << "ScavTrap constructor called" RES << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap() {
	std::cout << BLU << "ScavTrap copy constructor called" RES << std::endl;
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& original) {
	std::cout << PUR "ScavTrap copy assignment operator called" << RES << std::endl;
	if (this == &original)
		return (*this);
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap default denstructor called" RES << std::endl;
}

void ScavTrap::guardGate(void) {
	if (this->_h_pts == 0)
		std::cout << "ScavTrap " << this->_name << " is dead. Can't guard gate."
		<< std::endl;
	else if (this->_e_pts == 0)
		std::cout << "ScavTrap " << this->_name << " has no EP left. Can't guard gate."
		<< std::endl;
	else
		std::cout << BLU << "ScavTrap " << this->_name 
		<< " is now in Gate keeper mode." RES << std::endl;
}

void ScavTrap::attack(const std::string& target) {
if (this->_e_pts <= 0) {
		std::cout << YEL "ScavTrap " << this->_name 
		<< " has no EP and can't attack!" RES << std::endl;
		return ;
	}
	else if (this->_h_pts <= 0) {
		std::cout << RED "ScavTrap " << this->_name 
		<< " has no HP - dead Traps don't fight no more." RES << std::endl;
	}
	else {
		std::cout << RED "ScavTrap " << this->_name << " attacks " 
		<< target << ", causing up to " << this->_a_dmg << " points of damage!" RES << std::endl;
		this->_e_pts -= 1;
	}
}
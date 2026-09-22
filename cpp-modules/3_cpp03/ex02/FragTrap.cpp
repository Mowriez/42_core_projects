/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:01:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/22 20:21:02 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->_h_pts = 100;
	this->_e_pts = 100;
	this->_a_dmg = 30;
	std::cout << GRE << "FragTrap default constructor called" RES << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_h_pts = 100;
	this->_e_pts = 100;
	this->_a_dmg = 30;
	std::cout << GRE << "FragTrap constructor called" RES << std::endl;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap() {
	std::cout << BLU << "FragTrap copy constructor called" RES << std::endl;
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
}

FragTrap&	FragTrap::operator=(const FragTrap& original) {
	std::cout << PUR "FragTrap copy assignment operator called" << RES << std::endl;
	if (this == &original)
		return (*this);
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap default denstructor called" RES << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << ": Gimme Five, Brother." << std::endl;
}

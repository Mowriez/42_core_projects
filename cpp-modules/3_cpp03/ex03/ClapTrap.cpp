/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:21:36 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/20 14:40:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("noname"), _h_pts(10), _e_pts(10), _a_dmg(0) {
	std::cout << GRE << "ClapTrap default constructor called" RES << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _h_pts(10), _e_pts(10), _a_dmg(0) {
	std::cout << GRE << "ClapTrap constructor called" RES << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original) {
	std::cout << BLU << "ClapTrap copy constructor called" RES << std::endl;
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& original) {
	std::cout << PUR "ClapTrap copy assignment operator called" << RES << std::endl;
	if (this == &original)
		return (*this);
	this->_name = original._name;
	this->_h_pts = original._h_pts;
	this->_e_pts = original._e_pts;
	this->_a_dmg = original._a_dmg;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap default destructor called" RES << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_e_pts <= 0) {
		std::cout << YEL "ClapTrap " << this->_name 
		<< " has no EP and can't attack!" RES << std::endl;
		return ;
	}
	else if (this->_h_pts <= 0) {
		std::cout << RED "ClapTrap " << this->_name 
		<< " has no HP - dead Traps don't fight no more." RES << std::endl;
	}
	else {
		std::cout << RED "ClapTrap " << this->_name << " attacks " 
		<< target << ", causing up to " << this->_a_dmg << " points of damage!" RES << std::endl;
		this->_e_pts -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << RED << "ClapTrap " << this->_name << " took a hit with " 
	<< amount << " attack points. " RES << std::endl;
	if (this->_h_pts == 0) {
		std::cout << PUR << "ClapTrap " << this->_name << 
		" is already k.o., though. - no damage taken. (0 HP)" RES << std::endl;
		return ;
	}
	if (this->_h_pts <= amount) {
		this->_h_pts = 0;
		std::cout << RED << "ClapTrap " << this->_name << 
		" is sleeping with the fishes. (0 HP)" RES << std::endl;
		return ;
	}
	this->_h_pts -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage and has " 
	<< this->_h_pts << " HP left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_h_pts == 0)
		std::cout << RED << "ClapTrap " << this->_name << 
		" is already k.o. - can't repair itself. (0 HP)" << RES << std::endl;
	else if (this->_e_pts == 0) {
		std::cout << YEL << "ClapTrap " << this->_name << 
		" is exhausted - can't repair itself (0 EP)" << RES << std::endl;
	}
	else {
		this->_e_pts -= 1;
		if (this->_h_pts + amount > 100)
			this->_h_pts = 100;
		else
			this->_h_pts += amount;
		std::cout << GRE << "ClapTrap " << this->_name << " repairs up to " << amount 
		<< " HP. Back to a total of " << this->_h_pts << " HP." RES << std::endl;
		return ;
	}
}

//getters
std::string		ClapTrap::get_name() const {
	return (this->_name);
}

unsigned int	ClapTrap::get_hit_points() const {
	return (this->_h_pts);
}

unsigned int	ClapTrap::get_energy_points() const {
	return (this->_e_pts);
}

unsigned int	ClapTrap::get_attack_damage() const {
	return (this->_a_dmg);
}

//setters (deprecated)
void	ClapTrap::set_name(std::string name) {
	this->_name = name;
}

void	ClapTrap::set_hit_points(unsigned int new_value) {
	this->_h_pts = new_value;
}

void	ClapTrap::set_energy_points(unsigned int new_value) {
	this->_e_pts = new_value;
}

void	ClapTrap::set_attack_damage(unsigned int new_value) {
	this->_a_dmg = new_value;
}

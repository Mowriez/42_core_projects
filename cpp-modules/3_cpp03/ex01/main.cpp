/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:48:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/20 16:18:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {

	std::cout << "####----- constructors and assignment operator -----#####" << std::endl << std::endl;
	ScavTrap	Bob("Bob");
	ScavTrap	Joe("Joe");
	ScavTrap	Noname;
	Noname = Bob;

	std::cout << std::endl << "####----- initialisation and member fcts -----#####" << std::endl << std::endl;

	std::cout << "Stats Bob" RES << std::endl;
	std::cout << "Name: " << Bob.get_name() << " | HP: " << Bob.get_hit_points() << " | EP: " 
	<< Bob.get_energy_points() << " | AD: " << Bob.get_attack_damage() << std::endl;

	std::cout << "Stats Joe" RES << std::endl;
	std::cout << "Name: " << Joe.get_name() << " | HP: " << Joe.get_hit_points() << " | EP: " 
	<< Joe.get_energy_points() << " | AD: " << Joe.get_attack_damage() << std::endl;

	std::cout << std::endl << "####-----test fight -----#####" << std::endl << std::endl;

	for (int i = 0; i < 5; i++) {
		Bob.attack("Joe");
		Joe.takeDamage(Bob.get_attack_damage());
		std::cout << std::endl;
	}

	Bob.beRepaired(3);
	Joe.beRepaired(3);
	Joe.guardGate();
	Bob.guardGate();


	std::cout << std::endl << "####-----test fight end -----#####" << std::endl << std::endl;

	return 0;
}

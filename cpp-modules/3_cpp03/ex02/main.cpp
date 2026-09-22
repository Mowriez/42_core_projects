/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:48:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/20 16:21:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void) {

	std::cout << "####----- constructors and assignment operator -----#####" << std::endl << std::endl;
	FragTrap	Millie("Millie");
	FragTrap	Lisa("Lisa");
	FragTrap	Noname;
	Noname = Millie;

	std::cout << std::endl << "####----- initialisation and member fcts -----#####" << std::endl << std::endl;

	std::cout << "Stats Millie" RES << std::endl;
	std::cout << "Name: " << Millie.get_name() << " | HP: " << Millie.get_hit_points() << " | EP: " 
	<< Millie.get_energy_points() << " | AD: " << Millie.get_attack_damage() << std::endl;

	std::cout << "Stats Lisa" RES << std::endl;
	std::cout << "Name: " << Lisa.get_name() << " | HP: " << Lisa.get_hit_points() << " | EP: " 
	<< Lisa.get_energy_points() << " | AD: " << Lisa.get_attack_damage() << std::endl;

	std::cout << std::endl << "####-----test fight -----#####" << std::endl << std::endl;

	for (int i = 0; i < 5; i++) {
		Millie.attack("Lisa");
		Lisa.takeDamage(Millie.get_attack_damage());
		std::cout << std::endl;
	}

	Millie.beRepaired(3);
	Lisa.beRepaired(3);
	Lisa.highFivesGuys();

	std::cout << std::endl << "####-----test fight end -----#####" << std::endl << std::endl;

	return 0;
}

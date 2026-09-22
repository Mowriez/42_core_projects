/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:48:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/22 22:27:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {

	std::cout << "####----- constructors and assignment operator -----#####" << std::endl << std::endl;
	DiamondTrap	Tommy("Tommy");

	std::cout << std::endl << "####----- object info -----#####" << std::endl << std::endl;
	std::cout << "Stats Tommy" RES << std::endl;
	std::cout << "Name: " << Tommy.get_name() << " | HP: " << Tommy.get_hit_points() << " | EP: " 
	<< Tommy.get_energy_points() << " | AD: " << Tommy.get_attack_damage() << std::endl;


	std::cout << std::endl << "####-----test moves -----#####" << std::endl << std::endl;

	Tommy.attack("the Air");
	Tommy.beRepaired(3);
	Tommy.guardGate();
	Tommy.highFivesGuys();
	Tommy.whoAmI();

	std::cout << std::endl << "####-----test moves end -----#####" << std::endl << std::endl;

	return 0;
}

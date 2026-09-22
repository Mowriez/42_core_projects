/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:48:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/20 12:51:36 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {

	std::cout << "####----- constructors and assignment operator -----#####" << std::endl << std::endl;
	ClapTrap	Noname;
	ClapTrap	Elon("Elon");
	ClapTrap	Mark("Mark");
	ClapTrap	Noname2(Noname);
	Noname = Elon;

	std::cout << std::endl << "####----- initialisation and member fcts -----#####" << std::endl << std::endl;

	std::cout << "Stats Elon" RES << std::endl;
	std::cout << "Name: " << Elon.get_name() << " | HP: " << Elon.get_hit_points() << " | EP: " 
	<< Elon.get_energy_points() << " | AD: " << Elon.get_attack_damage() << std::endl;

	std::cout << "Stats Mark" RES << std::endl;
	std::cout << "Name: " << Mark.get_name() << " | HP: " << Mark.get_hit_points() << " | EP: " 
	<< Mark.get_energy_points() << " | AD: " << Mark.get_attack_damage() << std::endl;

	std::cout << std::endl << "####-----test fight -----#####" << std::endl << std::endl;
	std::cout << "Elon gets 3 EP and 3 AP, Mark gets 5 EP and 3 AP,"
	" both regenerate 3 HP per repair. HP lowered to 5, otherwise output is hard to read."
	 << std::endl << std::endl;

	Elon.set_attack_damage(2);
	Elon.set_energy_points(3);
	Elon.set_hit_points(5);
	Mark.set_attack_damage(3);
	Mark.set_energy_points(5);
	Mark.set_hit_points(5);

	std::cout << "Updated stats Elon" RES << std::endl;
	std::cout << "Name: " << Elon.get_name() << " | HP: " << Elon.get_hit_points() << " | EP: " 
	<< Elon.get_energy_points() << " | AD: " << Elon.get_attack_damage() << std::endl;
	std::cout << "Updated stats Mark" RES << std::endl;
	std::cout << "Name: " << Mark.get_name() << " | HP: " << Mark.get_hit_points() << " | EP: " 
	<< Mark.get_energy_points() << " | AD: " << Mark.get_attack_damage() << std::endl << std::endl;

	for (int i = 0; i < 2; i++) {
		Elon.attack("Mark");
		Mark.takeDamage(Elon.get_attack_damage());
		std::cout << std::endl;
		Mark.attack("Elon");
		Elon.takeDamage(Mark.get_attack_damage());
		std::cout << std::endl;
	}
	Elon.attack("Mark");
	Mark.attack("Elon");
	Elon.takeDamage(Mark.get_attack_damage());
	Elon.beRepaired(3);
	Mark.beRepaired(3);
	Mark.beRepaired(3);
	Mark.beRepaired(3);

	std::cout << std::endl << "####-----test fight end -----#####" << std::endl << std::endl;

	return 0;
}

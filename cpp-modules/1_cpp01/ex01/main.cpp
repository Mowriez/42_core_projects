/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:27:27 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:40:00 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main (void) {

	std::cout << GREEN << "----# Initialising horde 1 #----" 
	<< RESET << std::endl << std::endl;

	Zombie	*growlers = zombieHorde(3, "growler");

	std::cout << std::endl << GREEN << "----# Initialising horde 2 #----" 
	<< RESET << std::endl << std::endl;

	Zombie	*runners = zombieHorde(12, "runner");

	std::cout << std::endl << GREEN << "----# Announcing all hordes #----" 
	<< RESET << std::endl << std::endl;
	
	for (int i = 0; i < 3; i++)
		growlers[i].announce();
	for (int i = 0; i < 12; i++)
		runners[i].announce();

	std::cout << std::endl << GREEN << "----# Deleting Zombies #----" 
	<< RESET << std::endl << std::endl;

	delete [] growlers;
	delete [] runners;
	return (0);
}

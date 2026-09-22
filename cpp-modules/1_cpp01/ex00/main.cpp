/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:27:27 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:39:36 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main (void) {
	Zombie	*Brian;
	Zombie	*Susie;
	Zombie	*Millie;

	std::cout << GREEN << "----# Initialising both types of Zombies #----" 
	<< RESET << std::endl << std::endl;
	Brian = newZombie("Brian");
	Susie = newZombie("Susie");
	Millie = newZombie("Millie");
	randomChump("TrashZombie1");

	std::cout << std::endl << GREEN << "----# Announcing Zombies #----" 
	<< RESET << std::endl 
	<< std::endl;
	Brian->announce();
	Susie->announce();
	Millie->announce();
	randomChump("TrashZombie2");

	std::cout << std::endl << GREEN << "----# Deleting Zombies #----" 
	<< RESET << std::endl << std::endl;
	delete Brian;
	delete Susie;
	delete Millie;
	randomChump("TrashZombie3");
	return (0);
}

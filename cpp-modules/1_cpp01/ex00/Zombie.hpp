/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:54:20 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:39:26 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:
		std::string	name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
		void	set_name(std::string name);
};

// Text Colors
#define RESET "\033[0m"
#define GREEN "\033[1;32m"

// External function prototypes:
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif

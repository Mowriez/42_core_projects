/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:05:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/22 21:23:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	_name;
	
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& original);
		DiamondTrap&	operator=(const DiamondTrap& original);
		~DiamondTrap();
		
		void whoAmI();
		void attack(const std::string& target);

		std::string		get_name() const;
		unsigned int	get_hit_points() const;
		unsigned int	get_energy_points() const;
		unsigned int	get_attack_damage() const;
};

#endif

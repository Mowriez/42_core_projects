/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:06:06 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/22 21:14:51 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

// colors
# define RED "\033[1;31m"
# define PUR "\033[1;35m"
# define YEL "\033[1;33m"
# define GRE "\033[1;32m"
# define BLU "\033[1;34m"
# define RES "\033[0m"

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_h_pts;
		unsigned int	_e_pts;
		unsigned int	_a_dmg;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& original);
		ClapTrap&	operator=(const ClapTrap& original);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		get_name() const;
		unsigned int	get_hit_points() const;
		unsigned int	get_energy_points() const;
		unsigned int	get_attack_damage() const;

		void	set_name(std::string name);
		void	set_hit_points(unsigned int amount);
		void	set_energy_points(unsigned int amount);
		void	set_attack_damage(unsigned int amount);
};

#endif

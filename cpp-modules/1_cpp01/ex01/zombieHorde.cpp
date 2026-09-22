/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:32:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:40:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	Zombie* horde = new Zombie[N] ;
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}

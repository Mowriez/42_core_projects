/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:16:02 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/16 00:32:36 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "iostream"

Harl::Harl() {
	std::cout << BLUE "Harl initialised." RESET << std::endl;
}

Harl::~Harl() {
	std::cout << BLUE "Harl deleted." RESET << std::endl;
}

void	Harl::debug(void) {
	std::cout << GREEN "Debug: I love having extra bacon for " <<
	"my 7XL-double-cheese-triple-pickle-special-ketchup burger. " <<
	"I really do!" RESET << std::endl;
}

void	Harl::info(void) {
	std::cout << YELLOW "Info: I cannot believe adding extra bacon costs more money. " <<
	"You didn't put enough bacon in my burger! If you did, I wouldn't be asking" <<
	" for more!" RESET << std::endl;
}

void	Harl::warning(void) {
	std::cout << RED "Warning: I think I deserve to have some extra bacon for free. I've" <<
	" been coming for years whereas you started working here since last month." <<
	RESET << std::endl;
}

void	Harl::error(void) {
	std::cout << PURPLE "Error: This is unacceptable! I want to speak to the " <<
	"manager now." RESET << std::endl;
}

void	Harl::complain(std::string level) {
	void		(Harl::*func_ptr_arr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	complain_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	level_num = 4;
	for (int i = 0; i < 4; i++) {
		if (level == complain_arr[i]) {
			level_num = i;
			break ;
		}
	}
	
	switch (level_num) {
		case 0:
			(this->*func_ptr_arr[0])();
		case 1:
			(this->*func_ptr_arr[1])();
		case 2:
			(this->*func_ptr_arr[2])();
		case 3:
			(this->*func_ptr_arr[3])();
			break;
		default:
			std::cout << BLUE "[ Probably complaining about insignificant problems ]" RESET << std::endl;
	}
}


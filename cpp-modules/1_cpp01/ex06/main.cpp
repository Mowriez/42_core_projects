/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:16:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/16 00:31:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	Harl	Karen;

	if (argc != 2) {
		std::cout << "valid number of arguments: 1" << std::endl;
		return (1);
	}
	else {
		std::string	input = argv[1];
		Karen.complain(input);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:16:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/16 00:14:26 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(void) {
	Harl	Karen;

	std::cout << "------ DEBUG ------" << std::endl << std::endl;
	Karen.complain("debug");
	std::cout << std::endl << "------ INFO ------" << std::endl << std::endl;
	Karen.complain("info");
	std::cout << std::endl << "------ WARNING ------" << std::endl << std::endl;
	Karen.complain("warning");
	std::cout << std::endl << "------ ERROR ------" << std::endl << std::endl;
	Karen.complain("error");
}

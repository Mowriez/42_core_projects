/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:56:16 by mtrautne          #+#    #+#             */
/*   Updated: 2023/09/13 20:48:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {
	std::cout << "----------------------------------------------------------\n";
	std::cout << "|           TESTING initialization exceptions            |\n";
	std::cout << "----------------------------------------------------------\n";
	try {
		Form Contract("Contract", 1, 0);
		std::cout << Contract << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what();
	}
	std::cout << "---------------------------\n";
	try {
		Form Contract("Contract", 150, 151);
		std::cout << Contract << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what();
	}
	std::cout << "----------------------------------------------------------\n";
	std::cout << "|           TESTING member functions + exceptions        |\n";
	std::cout << "----------------------------------------------------------\n";
	Form Contract("Contract", 120, 105);
	Bureaucrat Alfred ("Alfred", 121);
	Bureaucrat Toby ("Toby", 120);
	std::cout << Contract << std::endl;
	std::cout << Alfred << std::endl;
	std::cout << Toby << std::endl;
	std::cout << "---------------------------\n";
	Alfred.signForm(Contract);
	std::cout << Contract << std::endl;
	std::cout << "---------------------------\n";
	Toby.signForm(Contract);
	Toby.signForm(Contract);
	std::cout << Contract << std::endl;
	std::cout << "---------------------------\n";
}

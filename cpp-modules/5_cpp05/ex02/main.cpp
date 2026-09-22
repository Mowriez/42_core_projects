/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:56:16 by mtrautne          #+#    #+#             */
/*   Updated: 2023/09/14 09:23:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void) {
	{
		std::cout << "----------------------------------------------------------\n";
		std::cout << "|    TESTING initialisation & signing PresidentialPF     |\n";
		std::cout << "----------------------------------------------------------\n";
		PresidentialPardonForm PPF("evaluator");
		Bureaucrat B1("B1", 1);
		Bureaucrat B2("B2", 55);
		std::cout << PPF << std::endl;
		std::cout << B1 << std::endl;
		std::cout << B2 << std::endl;
		std::cout << "---------------------------\n";
		B2.signForm(PPF);
		B1.executeForm(PPF);
		B1.signForm(PPF);
		std::cout << "---------------------------\n";
		B1.executeForm(PPF);
	}
	{
		std::cout << "----------------------------------------------------------\n";
		std::cout << "|               TESTING RobotomyRequestForm              |\n";
		std::cout << "----------------------------------------------------------\n";
		RobotomyRequestForm RRF("evaluator");
		Bureaucrat B1("B1", 1);
		Bureaucrat B2("B2", 100);
		std::cout << RRF << std::endl;
		std::cout << "---------------------------\n";
		B2.signForm(RRF);
		B1.executeForm(RRF);
		B1.signForm(RRF);
		std::cout << "---------------------------\n";
		B1.executeForm(RRF);
		std::cout << "---------------------------\n";
		B1.executeForm(RRF);
		std::cout << "---------------------------\n";
		B1.executeForm(RRF);
		std::cout << "---------------------------\n";
		B1.executeForm(RRF);
		std::cout << "---------------------------\n";
		B1.executeForm(RRF);
		std::cout << "---------------------------\n";
		B1.executeForm(RRF);
		std::cout << "---------------------------\n";
	}
	{
		std::cout << "----------------------------------------------------------\n";
		std::cout << "|             TESTING ShrubberyCreationForm              |\n";
		std::cout << "----------------------------------------------------------\n";
		ShrubberyCreationForm SCF("my garden");
		Bureaucrat B1("B1", 1);
		Bureaucrat B2("B2", 146);
		std::cout << SCF << std::endl;
		std::cout << "---------------------------\n";
		B2.signForm(SCF);
		B1.executeForm(SCF);
		B1.signForm(SCF);
		std::cout << "---------------------------\n";
		B1.executeForm(SCF);
	}
}

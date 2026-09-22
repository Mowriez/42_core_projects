/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:56:16 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/23 21:27:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void) { 
	{
		std::cout << "----------------------------------------------------------\n";
		std::cout << "|         TESTING specfics for new class Intern          |\n";
		std::cout << "----------------------------------------------------------\n";

		Intern I1;
		AForm* F1;
		AForm* F2;
		AForm* F3;
		Bureaucrat B1("B1", 1);
		std::cout << B1 << std::endl;
		std::cout << "---------------------------\n";
		try {
			F1 = I1.makeForm("presidential pardon", "evaluator1");
			F2 = I1.makeForm("shrubbery creation", "evaluator2");
			F3 = I1.makeForm("robotomy request", "evaluator3");
			I1.makeForm("Presidential Pardon", "Dummy");
		}
		catch (Intern::UnknownFormException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "---------------------------\n";
		std::cout << *F1 << std::endl;
		std::cout << *F2 << std::endl;
		std::cout << *F3 << std::endl;
		std::cout << "---------------------------\n";
		B1.signForm(*F1);
		B1.signForm(*F2);
		B1.signForm(*F3);
		std::cout << "---------------------------\n";
		B1.executeForm(*F1);
		B1.executeForm(*F2);
		B1.executeForm(*F3);
		std::cout << "---------------------------\n";
		delete F1;
		delete F2;
		delete F3;
	}
}

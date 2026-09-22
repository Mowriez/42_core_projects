/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:56:16 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/23 22:36:12 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	{
		std::cout << "----------------------------------------------------------\n";
		std::cout << "|           TESTING initialization exceptions            |\n";
		std::cout << "----------------------------------------------------------\n";
		try {
			Bureaucrat Toby("Toby", 0);
			std::cout << Toby << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << e.what();
		}
		std::cout << "---------------------------\n";
		try {
			Bureaucrat Toby("Toby", 151);
			std::cout << Toby << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cerr << e.what();
		}
	}
	std::cout << "----------------------------------------------------------\n";
	std::cout << "|           TESTING member functions + exceptions        |\n";
	std::cout << "----------------------------------------------------------\n";
	Bureaucrat Toby("Toby", 1);
	Bureaucrat Mike("Mike", 150);
	std::cout << Toby << std::endl;
	std::cout << Mike << std::endl;
	std::cout << "---------------------------\n";
	try {
		Toby.incrementGrade();
		std::cout << Toby << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what();
	}
	std::cout << "---------------------------\n";
	std::cout << Toby << std::endl;
	try {
		Toby.decrementGrade();
		Mike.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what();
	}
	std::cout << Toby << std::endl;
	std::cout << Mike << std::endl;
	std::cout << "---------------------------\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:47:29 by mtrautne          #+#    #+#             */
/*   Updated: 2023/09/14 09:26:56 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called." << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern default destructor called." << std::endl;
}

const char* Intern::UnknownFormException::what() const throw() {
	return ("Error: Unknown Form.");
}

AForm*	Intern::makeForm(std::string name, std::string target) const {
	int formId;
	AForm *retForm;
	std::string validForms[3] = {"presidential pardon", "shrubbery creation",
		"robotomy request"};

	for (formId = 0; formId < 3; formId++) {
		if (name == validForms[formId])
			break;
	}
	switch (formId) {
		case 0:
			 retForm = new PresidentialPardonForm(target);
			break;
		case 1:
			retForm = new ShrubberyCreationForm(target);
			break;
		case 2:
			retForm = new RobotomyRequestForm(target);
			break;
		default:
			throw Intern::UnknownFormException();
	}
	std::cout << "Intern creates form " << retForm->getName() 
		<< " with target " << target << std::endl;
	return (retForm);
}

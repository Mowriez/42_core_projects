/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:15:12 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/20 16:07:03 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", 145, 137, "noTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137, target) {
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm("ShrubberyCreationForm", other.getSignGrade(),
other.getExecGrade(),other.getTarget()) {
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm assignment operator overload called."
	<< std::endl;
	if (this == &other)
		return (*this);
	this->setTarget(other.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm std destructor called." << std::endl;
}

void ShrubberyCreationForm::performAction() const {
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outputFile(filename.c_str());

	outputFile << "       \\/ |    |/\n        \\/ / \\||/  /_/___/_\n         \\/   |/ \\/\n"
	<< "    _\\__\\_\\   |  /_____/_\n           \\  | /          /\n  __ _-----`  |{,-----------~\n"
	<< "            \\ }{\n             }{{\n             }}{\n             {{}\n"
	<< "       , -=-~{ .-^- _\n             `}\n              {" << std::endl;
	outputFile.close();
}

std::ostream& operator<<(std::ostream& output, const ShrubberyCreationForm& object) {
	output << object.getName() << " | sign_grade: " 
	<< object.getSignGrade() << " | exec_grade: " << object.getExecGrade() 
	<< " | signed status: " << object.getSignedStatus() << " | target: " << object.getTarget();
	return (output);
}

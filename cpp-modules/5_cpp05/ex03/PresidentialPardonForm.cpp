/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:15:12 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/22 19:24:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 25, "noTarget") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5, target) {
	std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm("PresidentialPardonForm", other.getSignGrade(),
		 other.getExecGrade(), other.getTarget()) {
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::
		operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm assignment operator overload called."
	<< std::endl;
	if (this == &other)
		return (*this);
	this->setTarget(other.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm default destructor called." << std::endl;
}

void PresidentialPardonForm::performAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& output, const PresidentialPardonForm& object) {
	output << object.getName() << " | sign_grade: " 
	<< object.getSignGrade() << " | exec_grade: " << object.getExecGrade() 
	<< " | signed status: " << object.getSignedStatus() << " | target: " << object.getTarget();
	return (output);
}

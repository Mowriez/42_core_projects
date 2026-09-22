/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:15:12 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/20 16:07:03 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45, "noTarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45, target) {
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm("RobotomyRequestForm", other.getSignGrade(),
		other.getExecGrade(), other.getTarget()) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::
		operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm assignment operator overload called."
	<< std::endl;
	if (this == &other)
		return (*this);
	this->setTarget(other.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm default destructor called." << std::endl;
}

void RobotomyRequestForm::performAction() const {
	int seed = std::clock();
	std::srand (seed);
	int random_value = std::rand() % 2;
	std::cout << "BRRRRRR >>drilling noises<<" << std::endl;
	if (random_value == 0)
		std::cout << "Robotomy failed." << std::endl;
	else
		std::cout << this->getTarget() <<" has been robotomized successfully."
		<< std::endl;
}

std::ostream& operator<<(std::ostream& output, const RobotomyRequestForm& object) {
	output << object.getName() << " | sign_grade: " 
	<< object.getSignGrade() << " | exec_grade: " << object.getExecGrade() 
	<< " | signed status: " << object.getSignedStatus() << " | target: " << object.getTarget();
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:16 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/19 18:04:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("garbageForm"), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target)
: _name(name), _signGrade(signGrade), _execGrade(execGrade),
 _signed(false), _target(target) {
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw(GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw(GradeTooLowException());
	std::cout << "AForm constructor called." << std::endl;
}

AForm::AForm(const AForm& other)
: _name(other.getName()), _signGrade(other.getSignGrade()),
_execGrade(other.getExecGrade()), _signed(other.getSignedStatus()),
_target(other.getTarget()) {
	std::cout << "AForm copy constructor called." << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator overload called." << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	this->_signed = other.getSignedStatus();
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm default destructor called." << std::endl;
}

std::string	AForm::getName() const {
	return (this->_name);
}

int	AForm::getSignGrade() const {
	return (this->_signGrade);
}

int	AForm::getExecGrade() const {
	return (this->_execGrade);
}

bool	AForm::getSignedStatus() const {
	return (this->_signed);
}

std::string	AForm::getTarget() const {
	return (this->_target);
}

void	AForm::setTarget(std::string target) {
	this->_target = target;
}

void	AForm::beSigned(const Bureaucrat& signee) {
	if (signee.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("AForm: Grade too high exception\n");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("AForm: Grade too low exception\n");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("AForm: Form not signed exception\n");
}

std::ostream& operator<<(std::ostream& output, const AForm& object) {
	output << object.getName() << ", Form sign_grade " << object.getSignGrade()
	<< ", exec_grade " << object.getExecGrade() << ", signed status: "
	<< object.getSignedStatus() << " | target: " << object.getTarget();
	return (output);
}

void	AForm::execute(Bureaucrat const & executor) {
	if (this->_signed == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else
		performAction();
}

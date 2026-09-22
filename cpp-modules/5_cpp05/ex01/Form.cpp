/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:16 by mtrautne          #+#    #+#             */
/*   Updated: 2023/09/13 20:47:07 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("garbageForm"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false),
	_signGrade(signGrade), _execGrade(execGrade) {
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw(GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw(GradeTooLowException()); 
	else
		std::cout << "Form constructor called." << std::endl;
}

Form::Form(const Form& other) : _name(other.getName()), _signed(other.getSignedStatus()),
	_signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()) {
	std::cout << "Form copy constructor called." << std::endl;
}

Form&	Form::operator=(const Form& other) {
	std::cout << "Form assignment operator overload called." << std::endl;
	if (this == &other)
		return (*this);
	this->_signed = other.getSignedStatus();
	return (*this);
}

Form::~Form() {
	std::cout << "Form default destructor called." << std::endl;
}

std::string	Form::getName() const {
	return (this->_name);
}

int	Form::getSignGrade() const {
	return (this->_signGrade);
}

int	Form::getExecGrade() const {
	return (this->_execGrade);
}

bool	Form::getSignedStatus() const {
	return (this->_signed);
}

void	Form::beSigned(const Bureaucrat& signee) {
	if (signee.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form: Grade too high exception\n");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form: Grade too low exception\n");
}

std::ostream& operator<<(std::ostream& output, const Form& object) {
	output << object.getName() << ", Form with sign grade " << object.getSignGrade()
	<< ", exec grade " << object.getExecGrade() << ", signed status: " << object.getSignedStatus();
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:23 by mtrautne          #+#    #+#             */
/*   Updated: 2023/09/13 21:09:13 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		Form();
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
public:
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSignedStatus() const;
		void		beSigned(const Bureaucrat& signee);

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& output, const Form& object);

#endif

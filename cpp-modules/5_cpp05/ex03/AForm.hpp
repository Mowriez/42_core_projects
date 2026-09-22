/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:23 by mtrautne          #+#    #+#             */
/*   Updated: 2023/09/13 21:14:13 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		AForm();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;
		std::string 		_target;

public:
		AForm(std::string name, int signGrade, int execGrade, std::string target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSignedStatus() const;
		std::string	getTarget() const;

		void		setTarget(std::string target);
		void		beSigned(const Bureaucrat& signee);

		void			execute(Bureaucrat const & executor);
		virtual void	performAction() const = 0;

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class	FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& output, const AForm& object);

#endif

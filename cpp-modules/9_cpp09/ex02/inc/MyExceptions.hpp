/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:09:22 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/10 21:44:10 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTIONS_HPP
# define MYEXCEPTIONS_HPP

# include <exception>
# include <string>
# include <iostream>
# include <sstream>

class NoInputException : public std::exception {
  public:
    const char* what() const throw();
};

class InvalidFormatException : public std::exception {
  private:
    std::string _errorMessage;
  public:
    InvalidFormatException(char* offendingNum);
    ~InvalidFormatException() throw () {};
    const char* what() const throw();
};

class OutOfRangeException : public std::exception {
  private:
    std::string _errorMessage;
  public:
    OutOfRangeException(const char* offendingNum);
    ~OutOfRangeException() throw () {};
    const char* what() const throw();
};

#endif

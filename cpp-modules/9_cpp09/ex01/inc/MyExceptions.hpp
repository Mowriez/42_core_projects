/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:20:50 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/25 16:09:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTIONS_HPP
# define MYEXCEPTIONS_HPP

# include <exception>
# include <string>
# include <iostream>
# include <sstream>

class MyBasicException : public std::exception {
  public:
    const char* what() const throw();
};

class WrongFormatException : public std::exception {
  private:
    std::string _errorMessage;
  public:
    WrongFormatException(const int& charNum, std::string& input);
    ~WrongFormatException() throw () {};
    const char* what() const throw();
};

class WrongBlockFormatException : public std::exception {
  private:
    std::string _errorMessage;
  public:
    WrongBlockFormatException(std::string& input);
    ~WrongBlockFormatException() throw () {};
    const char* what() const throw();
};

#endif

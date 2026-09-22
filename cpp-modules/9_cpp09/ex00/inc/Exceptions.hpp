/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:15:37 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 10:42:49 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>
# include <iostream>
# include <sstream>

class InputFileMissingException : public std::exception {
  public:
    const char* what() const throw();
};

class TooManyArgsException : public std::exception {
  public:
    const char* what() const throw();
};

class DataBaseFileAccessException : public std::exception {
  public:
    const char* what() const throw();
};

class DataBaseFileCorruptedException : public std::exception {
  private:
    std::string _errorMessage;
  public:

    DataBaseFileCorruptedException(int& lineNum);
    ~DataBaseFileCorruptedException() throw () {};
    const char* what() const throw();
};

class DataBaseEmptyException : public std::exception {
  public:
    const char* what() const throw();
};

class InputFileAccessException : public std::exception {
  public:
    const char* what() const throw();
};

class InvalidFormatException : public std::exception {
  private:
    std::string _errorMessage;
  public:

    InvalidFormatException(std::string& line);
    ~InvalidFormatException() throw () {};
    const char* what() const throw();
};

class InvalidDateException : public std::exception {
  private:
    std::string _errorMessage;
  public:

    InvalidDateException(std::string& line);
    ~InvalidDateException() throw () {};
    const char* what() const throw();
};

class NotPositiveNumberException : public std::exception {
  public:
    const char* what() const throw();
};

class TooLargeNumberException : public std::exception {
  public:
    const char* what() const throw();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:45:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 10:43:33 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Exceptions.hpp"

// for Input checking
const char* InputFileMissingException::what() const throw() {
  return ("Error: Input File not specified.");
}

const char* TooManyArgsException::what() const throw() {
  return ("Error: Too many args in function call.");
}

//---
// for DataBase file validity checking
const char* DataBaseFileAccessException::what() const throw() {
  return ("Error: Cannot open database file.");
}

DataBaseFileCorruptedException::DataBaseFileCorruptedException(int& lineNum) {
  std::stringstream ss;
  ss << "Error: Database file corrupted - line: " << lineNum;
  _errorMessage = ss.str();
}

const char* DataBaseFileCorruptedException::what() const throw() {
  return (_errorMessage.c_str());
}

const char* DataBaseEmptyException::what() const throw() {
  return ("Error: Database empty.");
}

const char* InputFileAccessException::what() const throw() {
  return ("Error: Input file not readable.");
}

InvalidFormatException::InvalidFormatException(std::string& line) {
  std::stringstream ss;
  ss << "Error: Bad input => " << line;
  _errorMessage = ss.str();
}

const char* InvalidFormatException::what() const throw() {
  return (_errorMessage.c_str());
}

InvalidDateException::InvalidDateException(std::string& line) {
  std::stringstream ss;
  ss << "Error: Bad date => " << line;
  _errorMessage = ss.str();
}

const char* InvalidDateException::what() const throw() {
  return (_errorMessage.c_str());
}

const char* NotPositiveNumberException::what() const throw() {
  return ("Error: not a positive number.");
}

const char* TooLargeNumberException::what() const throw() {
  return ("Error: too large a number.");
}

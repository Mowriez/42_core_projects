/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:09:49 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/10 21:44:28 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MyExceptions.hpp"

const char* NoInputException::what() const throw() {
  return ("Error: Invalid amount of arguments. (Needs at least 1)\n");
}

InvalidFormatException::InvalidFormatException(char* offendingNum) {
  std::stringstream ss;
  ss << "Error: Invalid input: " << offendingNum << std::endl;
  _errorMessage = ss.str();
}

const char* InvalidFormatException::what() const throw() {
  return (_errorMessage.c_str());
}

OutOfRangeException::OutOfRangeException(const char* offendingNum) {
  std::stringstream ss;
  ss << "Error: Out of range: |" << offendingNum << "|" << std::endl;
  _errorMessage = ss.str();
}

const char* OutOfRangeException::what() const throw() {
  return (_errorMessage.c_str());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Myexceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:17:25 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/11 21:34:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

#include <exception>

class SpanFullException : public std::exception {
  const char* what() const throw();
};

class SpanNotDisplayableException : public std::exception {
  const char* what() const throw();
};

class SpanToSmallForArrayException : public std::exception {
  const char* what() const throw();
};

#endif

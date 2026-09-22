/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:18:53 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/11 21:35:07 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MyExceptions.hpp"

const char* SpanFullException::what() const throw() {
  return ("Error: Can't add number to obj, already filled.");
}

const char* SpanNotDisplayableException::what() const throw() {
  return ("Error: Span has not enough individual elements to display  the"
          "shortest or longest Span.");
}

const char* SpanToSmallForArrayException::what() const throw() {
  return ("Error: Span has not enough empty elements to add the array.");
}

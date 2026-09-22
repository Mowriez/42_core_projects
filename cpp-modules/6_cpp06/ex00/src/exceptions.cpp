/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:30 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/11 18:22:30 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exceptions.hpp"

const char*	WrongArgumentNumException::what() const throw() {
	return ("Error: Wrong number of input arguments.");
}

const char*	InputInvalidException::what() const throw() {
	return ("Error: Input not of valid type or format.");
}

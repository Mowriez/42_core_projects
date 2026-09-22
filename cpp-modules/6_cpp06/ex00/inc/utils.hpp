/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:35:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/13 14:35:00 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CPP
# define UTILS_CPP

# include <string>
# include <cctype>
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <limits>
# include "exceptions.hpp"

enum	InputType{CHAR, INT, FLOAT, DOUBLE, UNKNOWN};

InputType	checkType(std::string& input);

bool		numericalPreCheckValid(std::string& input);

bool		isChar(std::string &input);
bool		isFloat(std::string &input);
bool		isDouble(std::string &input);
bool		isInteger(std::string &input);

void		convertChar(std::string &input);
void		convertInt(std::string &input);
void		convertDouble(std::string &input);
void		convertFloat(std::string &input);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:34:49 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/13 14:34:49 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

InputType	checkType(std::string &input) {
	if (isChar(input))
		return CHAR;
	else if (isFloat(input))
		return FLOAT;
	else if (isDouble(input))
		return DOUBLE;
	else if (isInteger(input))
		return INT;
	return UNKNOWN;
}

bool	numericalPreCheckValid(std::string& input) {
	size_t	periodCounter = 0;
	size_t	fCounter = 0;

	if (input == "-inff" || input == "+inff" || input == "-inf"
		|| input == "+inf" || input == "nanf" || input == "nan")
		return true;
	for (size_t it = 0; it < input.length(); it++) {
		if (!isdigit(input[it]) && input[it] != '.' && input[it] != 'f'
			&& input[it] != '+' && input[it] != '-')
			return false;
		if ((input[it] == '+' || input[it] == '-') && it != 0)
			return false;
		if (input[it] == 'f' && it != (input.length() - 1))
			return false;
		if (input[it] == 'f')
			fCounter++;
		if (input[it] == '.')
			periodCounter++;
		if (fCounter > 1 || periodCounter > 1)
			return false;
	}
	return (true);
}

bool	isChar(std::string &input) {
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		return true;
	return false;
}

bool	isFloat(std::string &input) {
	if (input == "nanf" || input == "inff" || input == "-inff")
		return true;
	else if (!numericalPreCheckValid(input))
		throw InputInvalidException();
	else if (input.length() > 2 && input.find('.') != std::string::npos
		&& input.find('f') == input.length() - 1)
		return true;
	return false;
}

bool	isDouble(std::string &input) {
	if (input == "nan" || input == "inf" || input == "-inf")
		return true;
	else if (!numericalPreCheckValid(input))
		throw InputInvalidException();
	else if (input.length() > 1 && input.find('.') != std::string::npos
		&& input.find('f') == std::string::npos)
		return true;
	return false;
}

bool	isInteger(std::string &input) {
	if (!numericalPreCheckValid(input))
		throw InputInvalidException();
	if (input.find('.') == std::string::npos
		&& input.find('f') == std::string::npos
		&& strtod(input.c_str(), NULL) < std::numeric_limits<int>::max()
		&& strtod(input.c_str(), NULL) > std::numeric_limits<int>::min()) {
		return true;
	}
	return false;
}

void	convertChar(std::string &input) {
	char	c = static_cast<char>(input.c_str()[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	convertInt(std::string &input) {
	int		i = static_cast<int>(atoi(input.c_str()));
	char 	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (input.length() > 6) {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
}

void	convertDouble(std::string &input) {
	double	d = static_cast<double>(strtod(input.c_str(), NULL));
	int		i = static_cast<int>(d);
	char 	c = static_cast<char>(d);
	float	f = static_cast<float>(d);

	if (floor(d) != d || i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (!isinf(d) && ((input[input.length() - 1] == '.' && input.find('.') < 9)
		|| (input[input.length() - 1] != '.' && floor(d) == d && input.find('.') < 7))) {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void	convertFloat(std::string &input) {
	float	f = static_cast<float>(atof(input.c_str()));
	double	d = static_cast<double>(f);
	int		i = static_cast<int>(f);
	char 	c = static_cast<char>(f);

	if (floor(f) != f || i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (!isinf(f) && ((input[input.length() - 2] == '.' && input.find('.') < 9)
		|| (input[input.length() - 2] != '.' && floor(f) == f && input.find('.') < 7)))
		 {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:17:29 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/10 17:17:29 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2) {
			throw WrongArgumentNumException();
		}
		else {
			std::string	input = argv[1];
			ScalarConverter::convert(input);
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

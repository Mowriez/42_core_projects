/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:45:22 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/11 13:44:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
	std::string		str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			str = argv[i];
			for (unsigned long j = 0; j < str.length(); j++)
				std::cout << static_cast<char>(std::toupper(str[j]));
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		return (1);
	return (0);
}

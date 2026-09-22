/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:25:34 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:12:09 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BetterSed.hpp"

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << RED "Invalid number of arguments!" RESET << std::endl;
		return (1);
	}
	else {
		std::string		filename = argv[1];
		std::ifstream	input_file(filename);

		if (!input_file.is_open()) {
			std::cout << RED "Failed to open input file" RESET << std::endl;
			return (1);
		}

		std::string		s1 = argv[2];
		std::string		s2 = argv[3];

		std::ofstream	output_file(filename + ".replaced");
		if(!output_file.is_open()) {
			std::cout << RED "Failed to create output file" RESET << std::endl;
			return (1);
		}

		std::string	line;
		while (std::getline(input_file, line)) {
			std::string	return_line;
			size_t	search_start_pos = 0;
			size_t	found_pos = line.find(s1, search_start_pos);

			while (found_pos != std::string::npos) {
				return_line += line.substr(search_start_pos, (found_pos - search_start_pos)) + s2;
				search_start_pos = found_pos + s1.length();
				found_pos = line.find(s1, search_start_pos);
			}
			return_line += line.substr(search_start_pos);
			output_file << return_line << std::endl;
		}
		input_file.close();
		output_file.close();
		std::cout << GREEN "File copied and replaced successfully." RESET << std::endl;
		return 0;
	}
}

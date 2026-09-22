/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:06:05 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/12 17:27:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./PhoneBook.hpp"

void	search_phonebook(PhoneBook phonebook, int i) {

	phonebook.print_phonebook(i);
			while (true) {
				std::string	index;

				std::cout << "For detailed view specifiy relevant index: ";
				std::getline(std::cin, index);
				if (std::cin.eof())
					return ;
				else if (index.size() == 0) {
					std::cout << "No index chosen, returning to main prompt." << std::endl;
					return ;
				}
				else {
					int index_numerical = std::atoi(index.c_str());
					if (index_numerical >= 0 && index_numerical < 8 && index_numerical < i)
						phonebook.print_contact(index_numerical);
					else
						std::cout << "Error: Non-valid index. Aborting search." << std::endl;
					break;
				}
			}
}

int	main(void) {

	std::string	input;
	PhoneBook	phonebook;
	int			i = 0;

	while (true) {

		std::string	input;

		std::cout << "phonebook> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		else if (input.size() == 0)
			std::cout << "valid commands: ADD, SEARCH and EXIT" << std::endl;
		else if (input == "EXIT")
			return (0);
		else if (input == "ADD") {
			phonebook.init_contact(i % 8);
			i++;
		}
		else if (input == "SEARCH")
			search_phonebook(phonebook, i);
	}
	return (0);
}

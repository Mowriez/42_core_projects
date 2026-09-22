/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:06:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/12 17:21:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::init_contact(int contact_number) {

	this->contacts[contact_number].populate_first_name();
	this->contacts[contact_number].populate_last_name();
	this->contacts[contact_number].populate_nick_name();
	this->contacts[contact_number].populate_number();
	this->contacts[contact_number].populate_secret();
}

std::string cut_long_entry(std::string input) {

	if (input.size() > 10)
		input = input.substr(0, 9) + ".";
	return (input);
}

void	PhoneBook::print_phonebook(int contact_num) {

	std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
	for (int i = 0; i < 8 && i < contact_num; i++) {
		std::cout << std::setw(10) << i << "|"
		<< std::setw(10) << cut_long_entry(this->contacts[i].get_first_name()) << "|"
		<< std::setw(10) << cut_long_entry(this->contacts[i].get_last_name()) << "|"
		<< std::setw(10) << cut_long_entry(this->contacts[i].get_nick_name()) << "|"
		<< std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::print_contact(int i) {

	std::cout << "first Name: " << this->contacts[i].get_first_name() << std::endl;
	std::cout << "last Name: " << this->contacts[i].get_last_name() << std::endl;
	std::cout << "nickname: " << this->contacts[i].get_nick_name() << std::endl;
	std::cout << "Phone Number: " << this->contacts[i].get_number() << std::endl;
	std::cout << "darkest secret: " << this->contacts[i].get_secret() << std::endl;
}

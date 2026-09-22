/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:11:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/12 14:45:31 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

// con-/destructors have no return type!
Contact::Contact() {
}

Contact::~Contact() {
}

void	Contact::populate_first_name() {

	while (true) {
		std::cout << "first name: ";
		std::getline(std::cin, this->first_name);
		if (std::cin.eof())
			break;
		if (first_name.empty()) {
			std::cout << "Error: cannot be empty. retry" << std::endl;
			continue;
			}
		else
			return ;
	}
}

void	Contact::populate_last_name() {

	while (true) {
		std::cout << "last name: ";
		std::getline(std::cin, this->last_name);
		if (std::cin.eof())
			break;
		if (last_name.empty()) {
			std::cout << "Error: cannot be empty. retry" << std::endl;
			continue;
			}
		else
			return ;
			}
}

void	Contact::populate_nick_name() {

	while (true) {
		std::cout << "nickname: ";
		std::getline(std::cin, this->nick_name);
		if (std::cin.eof())
			break;
		if (nick_name.empty()) {
			std::cout << "Error: cannot be empty. retry" << std::endl;
			continue;
			}
		else
			return ;
		}
}

void	Contact::populate_number() {

	while (true) {
		std::cout << "phone number: ";
		std::getline(std::cin, this->phone_number);
		if (std::cin.eof())
			break;
		if (phone_number.empty()) {
			std::cout << "Error: cannot be empty. retry" << std::endl;
			continue;
			}
		else
			return ;
		}
}

void	Contact::populate_secret() {

	while (true) {
		std::cout << "darkest secret: ";
		std::getline(std::cin, this->darkest_secret);
		if (std::cin.eof())
			break;
		if (darkest_secret.empty()) {
			std::cout << "Error: cannot be empty. retry" << std::endl;
			continue;
			}
		else
			return ;
		}
}

std::string	Contact::get_first_name() {
	return (this->first_name);
}

std::string	Contact::get_last_name() {
	return (this->last_name);
}

std::string	Contact::get_nick_name() {
	return (this->nick_name);
}

std::string	Contact::get_number() {
	return (this->phone_number);
}

std::string	Contact::get_secret() {
	return (this->darkest_secret);
}
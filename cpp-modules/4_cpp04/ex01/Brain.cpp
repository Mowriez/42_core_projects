/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:18:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 20:12:37 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "No good idea yet.";
	}
}

Brain::Brain(const Brain& original) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = original._ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& original) {
	std::cout << "Brain assignment operator overload called." << std::endl;
	if(this == &original)
		return (*this);
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = original._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

std::string	Brain::getIdea(int i) const {
	if (i < 0 || i >= 100)
		return ("");
	return (this->_ideas[i]);
}

void	Brain::setIdea(int i, std::string idea) {
	if (i < 0 || i >= 100) {
		std::cout << "i not in range of idea-array!" << std::endl;
		return ;
	}
	else
		this->_ideas[i] = idea;
}
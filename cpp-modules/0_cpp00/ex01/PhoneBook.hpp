/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:02:18 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/12 14:53:37 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {

	private:
		Contact	contacts[8];
	
	public:
		PhoneBook();
		~PhoneBook();
		void	print_phonebook(int contact_number);
		void	print_contact(int i);
		void	init_contact(int contact_number);

};

#endif
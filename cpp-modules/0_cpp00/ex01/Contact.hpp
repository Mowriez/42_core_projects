/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:49:43 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/12 13:52:56 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;


	public:
		Contact();
		~Contact();
		void	populate_first_name();
		void	populate_last_name();
		void	populate_nick_name();
		void	populate_number();
		void	populate_secret();

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nick_name();
		std::string	get_number();
		std::string	get_secret();
		;
};

#endif
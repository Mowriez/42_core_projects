/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:50:34 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/15 23:40:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {

	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::endl << "\033[1;32m" << "----# Adresses #----" 
	<< "\033[0m" << std::endl << std::endl;
	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl << "\033[1;32m" << "----# Values #----" 
	<< "\033[0m" << std::endl << std::endl;
	std::cout << "value of str: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:16:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/16 00:15:49 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef HARL_HPP
# define HARL_HPP

#define RED "\033[1;31m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class Harl {

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif

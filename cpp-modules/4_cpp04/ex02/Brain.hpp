/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:16:51 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/23 22:03:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef	BRAIN_HPP
# define BRAIN_HPP

class Brain {
	protected:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& original);
		Brain&	operator=(const Brain& original);
		virtual ~Brain();

		std::string	getIdea(int i) const;
		void		setIdea(int i, std::string idea);
};

#endif

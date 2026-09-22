/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:15:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/11 13:07:55 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

class NotFoundException : public std::exception {
  public:
    const char* what() const throw() {
     return ("Error: Element was not found in the container.");
  }
};

template <typename T>
void easyfind(T container, int argToFind) {
  typename T::iterator it = find(container.begin(), container.end(), argToFind);
  if (*it == argToFind) {
      std::cout << "Success! " << argToFind << " was found in container at pos "
      << distance(container.begin(), it)  << std::endl;
    }
  else if (it == container.end())
    throw NotFoundException();
}

template<>
void easyfind<std::map<int, int> >(std::map<int, int> container, int argToFind) {
  std::map<int, int>::iterator	it = container.find(argToFind);
    if (it->second == argToFind) {
      std::cout << "Success! " << argToFind << " was found in container at key "
      << it->first  << std::endl;
    }
  else if (it == container.end())
    throw NotFoundException();
}

#endif

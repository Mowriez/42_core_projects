/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:50:22 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/11 13:28:50 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <list>
#include <map>

int main() {
  try {
    std::vector<int>  vect;
    std::list<int>  list;
    std::map<int, int>  map;
  for (size_t i = 0; i < 5;  i++) {
      vect.push_back(i);
      list.push_back(i);
      map.insert(std::pair<int, int>(i, i));
  }
  easyfind(vect, 2);
  easyfind(list, 3);
  easyfind(map, 4);
  easyfind(list, 6);
  }
  catch(NotFoundException &e) {
    std::cerr << e.what() << std::endl;
  }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:46:01 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 14:15:19 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MyExceptions.hpp"
#include "../inc/PmergeMe.hpp"

int main(int argc, char** argv) {
  try {
    if (argc < 2)
      throw NoInputException();

    PmergeMe sortObject(argc, argv);

    sortObject.printUnsorted();
    sortObject.sortDeque();
    sortObject.sortVector();
    sortObject.printSorted();
    sortObject.printSortStatistics();
  }

  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

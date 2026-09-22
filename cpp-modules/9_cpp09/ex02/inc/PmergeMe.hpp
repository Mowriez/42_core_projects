/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:10:37 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 13:55:07 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <deque>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "MyExceptions.hpp"
# include "utilsDeque.hpp"
# include "utilsVector.hpp"

class PmergeMe {
  private:
    int              _numArgs;
    char**           _inputArray;

    std::deque<int>  _unsortedDeque;
    std::vector<int>   _unsortedVector;

    double           _sortTimeDeque;
    double           _sortTimeVector;

    std::deque<int>  _sortedDeque;
    std::vector<int>   _sortedVector;

    void  parseInputArray();

  public:
    PmergeMe(int argc, char** input);
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void  sortDeque();
    void  sortVector();

    void  printUnsorted();
    void  printSorted();
    void  printSortStatistics();
    };

#endif

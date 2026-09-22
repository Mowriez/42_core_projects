/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:12:32 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 14:17:57 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** input)
  : _numArgs(argc - 1), _inputArray(input) {
  parseInputArray();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
  this->_numArgs = other._numArgs;
  this->_inputArray = other._inputArray;
  this->_unsortedDeque = other._unsortedDeque;
  this->_unsortedVector = other._unsortedVector;
  this->_sortTimeDeque = other._sortTimeDeque;
  this->_sortTimeVector = other._sortTimeVector;
  this->_sortedDeque = other._sortedDeque;
  this->_sortedVector = other._sortedVector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this == &other)
    return (*this);
  else {
    this->_numArgs = other._numArgs;
    this->_inputArray = other._inputArray;
    this->_unsortedDeque = other._unsortedDeque;
    this->_unsortedVector = other._unsortedVector;
    this->_sortTimeDeque = other._sortTimeDeque;
    this->_sortTimeVector = other._sortTimeVector;
    this->_sortedDeque = other._sortedDeque;
    this->_sortedVector = other._sortedVector;
  }
  return (*this);
}

void  PmergeMe::parseInputArray() {
  for (size_t i = 1; _inputArray[i] != NULL; i++) {
    char* endptr;
    long numLong = std::strtol(_inputArray[i], &endptr, 10);
    if ((numLong < 0 || numLong > 2147483647 || *endptr != '\0'))
      throw InvalidFormatException(_inputArray[i]);
    int numInt = static_cast<int>(numLong);
    _unsortedDeque.push_back(numInt);
    _unsortedVector.push_back(numInt);
  }
}

void  PmergeMe::sortDeque() {
  clock_t sortStart = clock();
  if (_unsortedDeque.size() == 1) {
    _sortedDeque = _unsortedDeque;
    clock_t sortEnd = clock();
    _sortTimeDeque = static_cast<double>(sortEnd - sortStart) / CLOCKS_PER_SEC;
    return ;
  }
  int straggler = handleStraggler(_unsortedDeque);
  std::deque<std::deque<int> > helpDeque = createPairs(_unsortedDeque);
  sortIndividualPairs(helpDeque);
  insertionSortPairs(helpDeque, helpDeque.size());
  _sortedDeque = createSortedDeque(helpDeque);
  if (straggler != -1)
    binaryInsertionSort(straggler, _sortedDeque, 0, _sortedDeque.size() - 1);
  clock_t sortEnd = clock();
  _sortTimeDeque = static_cast<double>(sortEnd - sortStart) / CLOCKS_PER_SEC;
}

void  PmergeMe::sortVector() {
  clock_t sortStart = clock();
    if (_unsortedVector.size() == 1) {
    _sortedVector = _unsortedVector;
    clock_t sortEnd = clock();
    _sortTimeVector = static_cast<double>(sortEnd - sortStart) / CLOCKS_PER_SEC;
    return ;
  }
  int straggler = handleStraggler(_unsortedVector);
  std::vector<std::vector<int> > helpVector = createPairs(_unsortedVector);
  sortIndividualPairs(helpVector);
  insertionSortPairs(helpVector, helpVector.size());
  _sortedVector = createSortedVector(helpVector);
  if (straggler != -1)
    binaryInsertionSort(straggler, _sortedVector, 0, _sortedVector.size() - 1);
  clock_t sortEnd = clock();
  _sortTimeVector = static_cast<double>(sortEnd - sortStart) / CLOCKS_PER_SEC;
}

// printing stuff
void  PmergeMe::printUnsorted() {
  size_t i = 0;
  std::cout << "Before:  ";
  for (std::deque<int>::const_iterator it = _unsortedDeque.begin(); 
        it != _unsortedDeque.end(); it++) {
    std::cout << *it << " ";
    if (i > 4) {
      std::cout << "[...]";
      break;
    }
    i++;
  }
  std::cout << std::endl;
}

void  PmergeMe::printSorted() {
  size_t i = 0;
  std::cout << "After:   ";
  for (std::deque<int>::const_iterator it = _sortedDeque.begin(); 
        it != _sortedDeque.end(); it++) {
    std::cout << *it << " ";
    if (i > 4) {
      std::cout << "[...]";
      break;
    }
    i++;
  }
  std::cout << std::endl;
}

void  PmergeMe::printSortStatistics() {
  if (_unsortedDeque.size() < 200) {
    std::cout << "Time to process a range of " << _numArgs 
      << " elements with std::deque : " << std::fixed << std::setprecision(5)
      << _sortTimeDeque * 1000000 << " us" << std::endl;
    std::cout << "Time to process a range of " << _numArgs 
      << " elements with std::vector :  " << std::fixed << std::setprecision(5)
      << _sortTimeVector * 1000000 << " us" << std::endl;
  }
  else {
  std::cout << "Time to process a range of " << _numArgs 
    << " elements with std::deque : " << std::fixed << std::setprecision(5)
    << _sortTimeDeque  << " s" << std::endl;
  std::cout << "Time to process a range of " << _numArgs 
    << " elements with std::vector :  " << std::fixed << std::setprecision(5)
    << _sortTimeVector << " s" << std::endl;
  }
}

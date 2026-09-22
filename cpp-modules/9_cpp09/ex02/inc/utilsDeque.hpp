/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsDeque.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:50:06 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 13:45:08 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSDEQUE_HPP
# define UTILSDEQUE_HPP

# include <string>
# include <iostream>
# include <deque>
# include "MyExceptions.hpp"

void  printDeque(const std::deque<int>& deque);
void  printDoubleDeque(const std::deque<std::deque<int> >& deque);

int   handleStraggler(std::deque<int>& deque);

std::deque<std::deque<int> >  createPairs(const std::deque<int>& deque);

void  sortIndividualPairs(std::deque<std::deque<int> >& deque);
void  sortPairsByLargerValue(std::deque<std::deque<int> >& deque);
void  insertionSortPairs(std::deque<std::deque<int> >& pairedDeque, int len);

std::deque<int>  createSortedDeque(std::deque<std::deque<int> >& sortedPairedDeque);
void  binaryInsertionSort(int num, std::deque<int>& fullySortedDeque, int low, int high);
void  insert(int num, int pos, std::deque<int>& deque);

// std::deque<int>  createJacobsthalSequence(size_t n);
// size_t           jacobsthal(size_t i, std::deque<int> sequence);

#endif

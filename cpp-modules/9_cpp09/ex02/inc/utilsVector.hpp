/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsVector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:50:06 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 13:44:54 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSVECTOR_HPP
# define UTILSVECTOR_HPP

# include <string>
# include <iostream>
# include <vector>
# include "MyExceptions.hpp"

void  printVector(const std::vector<int>& vector);
void  printDoubleVector(const std::vector<std::vector<int> >& vector);

int   handleStraggler(std::vector<int>& vector);

std::vector<std::vector<int> >  createPairs(const std::vector<int>& vector);

void  sortIndividualPairs(std::vector<std::vector<int> >& vector);
void  sortPairsByLargerValue(std::vector<std::vector<int> >& vector);
void  insertionSortPairs(std::vector<std::vector<int> >& pairedVector, int len);

std::vector<int>  createSortedVector(std::vector<std::vector<int> >& sortedPairedVector);
void  binaryInsertionSort(int num, std::vector<int>& fullySortedVector, int low, int high);
void  insert(int num, int pos, std::vector<int>& vector);


#endif

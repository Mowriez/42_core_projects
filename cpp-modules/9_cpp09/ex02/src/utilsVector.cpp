/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsVector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:52:43 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 14:05:51 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utilsVector.hpp"

void  printVector(const std::vector<int>& vector) {
  int i = 0;
  for(std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); 
      it++) {
    std::cout << "vector[" << i <<"]: " << *it << " ";
    i++;
  }
}

void  printDoubleVector(const std::vector<std::vector<int> >& vector) {
  int i = 0;
  for(std::vector<std::vector<int> >::const_iterator it = vector.begin(); 
      it != vector.end(); it++) {
    std::cout << "Outer vector[" << i <<"]: ";
    printVector(*it);
    std::cout << std::endl;
    i++;
  }
}

int  handleStraggler(std::vector<int>& vector) {
    int ret = -1;
  if(vector.size() % 2 != 0) {
    ret = *(--vector.end());
    vector.pop_back();
  }
  return (ret);
}

std::vector<std::vector<int> > createPairs(const std::vector<int>& vector) {
  std::vector<std::vector<int> > retVector;
  for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end();
       it++) {
    std::vector<int> pair;
    pair.push_back(*it);
    pair.push_back(*++it);
    retVector.push_back(pair);
  }
  return retVector;
}

void  sortIndividualPairs(std::vector<std::vector<int> >& vector) {
  for (std::vector<std::vector<int> >::iterator it = vector.begin();
       it != vector.end(); it++) {
    if ((*it)[0] > (*it)[1]) {
      int temp = (*it)[0];
      (*it)[0] = (*it)[1];
      (*it)[1] = temp;
    }
  }
}


void  insertionSortPairs(std::vector<std::vector<int> >& pairedVector, int n) {
  if (n <= 1)
    return ;
  insertionSortPairs(pairedVector, n - 1);

  //put last element at correct place
  std::vector<int> lastElement = pairedVector[n - 1];
  int j = n - 2;
  //move all elements > last Element in vector before last Element one position further
  while (j >= 0 && pairedVector[j][1] >= lastElement[1]) {
    pairedVector[j + 1] = pairedVector[j];
    j--;
  }
  pairedVector[j + 1] = lastElement;
}

std::vector<int>  createSortedVector(std::vector<std::vector<int> >& sortedPairedVector) {
  std::vector<int> S;
  std::vector<int> pend;

  // insert bigger numbers of pairs in S and smaller in pend
  for (std::vector<std::vector<int > >::iterator it = sortedPairedVector.begin(); 
        it != sortedPairedVector.end(); it++) {
          S.push_back((*it)[1]);
          pend.push_back((*it)[0]);
        }
  // add smallest number at beginning of S
  S.insert(S.begin(), pend[0]);
  pend.erase(pend.begin());

  // insert rest of pend into S
  for (std::vector<int>::iterator it = pend.begin(); it != pend.end(); it++) {
    binaryInsertionSort(*it, S, 0, S.size() - 1);
  }
  return S;
}

void  binaryInsertionSort(int num, std::vector<int>& fullySortedVector, int low, int high) {
  if (low >= high) {
    if (num > fullySortedVector[low])
      insert(num, low + 1, fullySortedVector);
    else
      insert(num, low, fullySortedVector);
    return ;
  }
  int mid = (low + high) / 2;
  if (num == fullySortedVector[mid])
    insert(num, mid + 1, fullySortedVector);
  else if (num > fullySortedVector[mid])
    binaryInsertionSort(num, fullySortedVector, mid + 1, high);
  else if (num < fullySortedVector[mid])
    binaryInsertionSort(num, fullySortedVector, low, mid - 1);
}

void  insert(int num, int pos, std::vector<int>& vector) {
  int i = 0;
  std::vector<int>::iterator it;
  for (it = vector.begin(); it != vector.end(); it++) {
    if (i == pos)
      break;
    i++;
  }
  vector.insert(it, num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsDeque.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:52:43 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/24 14:17:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utilsDeque.hpp"

void  printDeque(const std::deque<int>& deque) {
  int i = 0;
  for(std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); 
      it++) {
    std::cout << "Deque[" << i <<"]: " << *it << " ";
    i++;
  }
}

void  printDoubleDeque(const std::deque<std::deque<int> >& deque) {
  int i = 0;
  for(std::deque<std::deque<int> >::const_iterator it = deque.begin(); 
      it != deque.end(); it++) {
    std::cout << "Outer Deque[" << i <<"]: ";
    printDeque(*it);
    std::cout << std::endl;
    i++;
  }
}

int  handleStraggler(std::deque<int>& deque) {
    int ret = -1;

  if(deque.size() % 2 != 0) {
    ret = *(--deque.end());
    deque.pop_back();
  }
  return (ret);
}

std::deque<std::deque<int> > createPairs(const std::deque<int>& deque) {
  std::deque<std::deque<int> > retDeque;
  for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end();
       it++) {
    std::deque<int> pair;
    pair.push_back(*it);
    pair.push_back(*++it);
    retDeque.push_back(pair);
  }
  return retDeque;
}

void  sortIndividualPairs(std::deque<std::deque<int> >& deque) {
  for (std::deque<std::deque<int> >::iterator it = deque.begin();
       it != deque.end(); it++) {
    if ((*it)[0] > (*it)[1]) {
      int temp = (*it)[0];
      (*it)[0] = (*it)[1];
      (*it)[1] = temp;
    }
  }
}


void  insertionSortPairs(std::deque<std::deque<int> >& pairedDeque, int n) {
  if (n <= 1)
    return ;
  insertionSortPairs(pairedDeque, n - 1);

  //put last element at correct place
  std::deque<int> lastElement = pairedDeque[n - 1];
  int j = n - 2;
  //move all elements > last Element in deque before last Element one position further
  while (j >= 0 && pairedDeque[j][1] >= lastElement[1]) {
    pairedDeque[j + 1] = pairedDeque[j];
    j--;
  }
  pairedDeque[j + 1] = lastElement;
}

std::deque<int>  createSortedDeque(std::deque<std::deque<int> >& sortedPairedDeque) {
  std::deque<int> S;
  std::deque<int> pend;

  // insert bigger numbers of pairs in S and smaller in pend
  for (std::deque<std::deque<int > >::iterator it = sortedPairedDeque.begin(); 
        it != sortedPairedDeque.end(); it++) {
          S.push_back((*it)[1]);
          pend.push_back((*it)[0]);
        }
  // add smallest number at beginning of S
  S.push_front(pend[0]);
  pend.pop_front();

  // insert rest of pend into S
  for (std::deque<int>::iterator it = pend.begin(); it != pend.end(); it++) {
    binaryInsertionSort(*it, S, 0, S.size() - 1);
  }
  return S;
}

void  binaryInsertionSort(int num, std::deque<int>& fullySortedDeque, int low, int high) {
  if (low >= high) {
    if (num > fullySortedDeque[low])
      insert(num, low + 1, fullySortedDeque);
    else
      insert(num, low, fullySortedDeque);
    return ;
  }
  int mid = (low + high) / 2;
  if (num == fullySortedDeque[mid])
    insert(num, mid + 1, fullySortedDeque);
  else if (num > fullySortedDeque[mid])
    binaryInsertionSort(num, fullySortedDeque, mid + 1, high);
  else if (num < fullySortedDeque[mid])
    binaryInsertionSort(num, fullySortedDeque, low, mid - 1);
}

void  insert(int num, int pos, std::deque<int>& deque) {
  int i = 0;
  std::deque<int>::iterator it;
  for (it = deque.begin(); it != deque.end(); it++) {
    if (i == pos)
      break;
    i++;
  }
  deque.insert(it, num);
}

// std::deque<int>  createJacobsthalSequence(size_t n) {
//   std::deque<int> sequence;
//   size_t i = 2;

//   sequence.push_back(0);
//   sequence.push_back(1);

//   while(i < n) {
//     sequence.push_back(sequence[i - 1] + (2 * sequence[i - 2]));
//     i++;
//   }
//   return sequence;
// }

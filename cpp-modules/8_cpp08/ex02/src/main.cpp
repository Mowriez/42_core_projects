/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:18:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <list>

int main(void) {
  std::cout << std::endl
            << "#######################################################\n"
            << "#####------------Tests-for-MutantStack------------#####"
            << std::endl;
  std::cout << "Instantiate and fill MutantStack object" << std::endl << std::endl;
  MutantStack<int> mstack;
  int i = 0;
  while (i < 5) {
    mstack.push(i * i);
    mstack.push(-i * i);
    i++;
  }
  std::cout << "Finished adding 10 elements to the MutantStack" << std::endl 
    << std::endl;
  std::cout << "MutantStack content:" << std::endl;
  int j = 0;
  for (MutantStack<int>::iterator itMStack = mstack.begin();
         itMStack != mstack.end(); itMStack++) {
    std::cout << "mstack[" << j++ << "]: " << *itMStack << std::endl;
  }
  std::cout << "Mutant Stack end " << std::endl << std::endl;
  std::cout << "Basic functions of stack to show they work for MutantStack" 
    << std::endl;
  std::cout << "Top: " << mstack.top() << std::endl;
  std::cout << "Size: " << mstack.size() << std::endl;
  mstack.pop();
  std::cout << "Popping the top element makes " << mstack.top() 
    << " the new top element.\nThe new size is: " << mstack.size() 
    << std::endl << std::endl;
  
  std::cout << "Iterator Magic, show begin and end" << std::endl;
  MutantStack<int>::iterator itMStack2 = mstack.begin();
  MutantStack<int>::iterator itEnd = mstack.end();
  std::cout << "Begin: " << *itMStack2 << std::endl;
  std::cout << "End: " << *itEnd << std::endl;
  ++itMStack2;
  ++itMStack2;
  std::cout << "Iterating the Iterator twice makes *it: " << *itMStack2 << std::endl;

//List comparison
  std::cout << std::endl
            << "#######################################################\n"
            << "#####--------Tests-for-List-as-comparison---------#####"
            << std::endl;
  std::cout << "Instantiate and fill list object" << std::endl << std::endl;
  std::list<int> myList;
  int k = 0;
  while (k < 5) {
    myList.push_back(k * k);
    myList.push_back(-k * k);
    k++;
  }
  std::cout << "Finished adding 10 elements to the list" << std::endl 
    << std::endl;
  std::cout << "list content:" << std::endl;
  int l = 0;
  for (std::list<int>::iterator itList = myList.begin(); itList != myList.end(); itList++) {
    std::cout << "myList[" << l++ << "]: " << *itList << std::endl;
  }
  std::cout << "List end " << std::endl << std::endl;
  std::cout << "Basic functions of stack to show they work for list" 
    << std::endl;
  std::cout << "Back: " << myList.back() << std::endl;
  std::cout << "Size: " << myList.size() << std::endl;
  myList.pop_back();
  std::cout << "Popping the back element makes " << myList.back() 
    << " the new back element.\nThe new size is: " << myList.size() 
    << std::endl << std::endl;
  
  std::cout << "Iterator Magic, show begin and end" << std::endl;
  std::list<int>::iterator itList2 = myList.begin();
  std::list<int>::iterator itEnd2 = myList.end();
  std::cout << "Begin: " << *itList2 << std::endl;
  std::cout << "End: " << *(--itEnd2) << std::endl;
  ++itList2;
  ++itList2;
  std::cout << "Iterating the Iterator twice makes *it: " << *itList2 << std::endl;
  return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:44:09 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/12 16:26:02 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main(void) {
  try {
    std::cout << std::endl;
    unsigned int N = 15000;
    Span  testSpan = Span(N);

    std::cout << "fill the Span with values 0 to N" << std::endl;
    for (size_t i = 0; i < N - 10; i++) {
      testSpan.addNumber(i * i);
    }
    testSpan.addNumber(-5);
    std::cout << "done filling" << std::endl << std::endl;

    std::cout << "Show the content of the Span" << std::endl;
    size_t i = 0;
    for (std::list<int>::const_iterator it = testSpan.getElements().begin(); 
      it != testSpan.getElements().end(); it++) {
      std::cout << "Span[" << i << "]: " << *it << std::endl;
      i++;
    }
    std::cout << std::endl;
    std::cout << "Shortest Span: " << testSpan.shortestSpan() << std::endl << std::endl;
    std::cout << "Longest Span: " << testSpan.longestSpan() << std::endl << std::endl;
    
    std::cout << "Add a list of numbers to Span" << std::endl;
    std::list<int> addList;

    for (size_t i = 0; i < 8; i++) {
      addList.push_back(i);
    }
    testSpan.addMultipleNumbers(addList.begin(), addList.end());
    std::list<int>::const_iterator it2 = testSpan.getElements().begin();
    int j = 14989;
    advance(it2, j);
    while (it2 != testSpan.getElements().end()) {
      std::cout << "Element[" << j++ << "]: " << *it2 << std::endl;
      it2++;
    }
    std::cout << std::endl << "Add numbers until the Span is full" << std::endl;
    testSpan.addNumber(10);
    std::cout << "last Element is " << *(--(testSpan.getElements().end())) << std::endl;
    testSpan.addMultipleNumbers(addList.begin(), addList.end());
    std::cout << "last Element is " << *(--(testSpan.getElements().end())) << std::endl;
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}

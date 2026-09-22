/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:51:32 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/11 21:32:29 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int N)
    : _elements(std::list<int>(N)), _size(N), _emptyElements(N) {
  std::cout << "Span created. Size is: " << _elements.size() << std::endl;
}

Span::~Span() {
  std::cout << "Default destructor" << std::endl;
}

Span::Span(const Span& other) 
    : _elements(other._elements), _size(other._size), _emptyElements(other._emptyElements) {
  std::cout << "Copy constructor" << std::endl;
}

Span& Span::operator=(Span& other) {
  if (this == &other)
    return (*this);
  else {
    _elements = other._elements;
    _size = other._size;
    _emptyElements = other._emptyElements;
  }
  return (*this);
}

const std::list<int>&   Span::getElements() const {
  return (_elements);
}

void  Span::addNumber(int newElement) {
  if (_emptyElements == 0)
    throw SpanFullException();
  else {
    std::list<int>::iterator it = _elements.begin();
    advance(it, _size - _emptyElements);
    *it = newElement;
    _emptyElements--;
  }
}

int  Span::shortestSpan() const {
  if (_size < 2)
    throw SpanNotDisplayableException();

  std::list<int> tmp = _elements;
  std::list<int>::iterator it = tmp.begin();
  advance(it, _size - _emptyElements);

  while (it != tmp.end()) {
    it = tmp.erase(it);
  }
  
  tmp.sort();
  std::list<int>::iterator it2 = tmp.begin();

  int shortestSpan = abs(*it2 - *(++it2));
  it2--;
  while (it2 != tmp.end()) {
      if (++it2 == tmp.end())
        break;
      it2--;
      int currentSpan = abs(*it2 - *(++it2));
      it2--;
      if (currentSpan < shortestSpan)
        shortestSpan = currentSpan;
    it2++;
  }
  return (shortestSpan);
}

int  Span::longestSpan() const {
  if (_size < 2)
    throw SpanNotDisplayableException();

  std::list<int> tmp = _elements;
  std::list<int>::iterator it = tmp.begin();
  advance(it, _size - _emptyElements);

  while (it != tmp.end()) {
    it = tmp.erase(it);
  }

  std::list<int>::iterator smallestElement = min_element(tmp.begin(), tmp.end());
  std::list<int>::iterator biggestElement = max_element(tmp.begin(), tmp.end());
  int longestSpan = abs(*smallestElement - *biggestElement);
  return (longestSpan);
}



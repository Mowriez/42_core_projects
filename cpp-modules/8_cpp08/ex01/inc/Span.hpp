/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:52:13 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/11 21:35:02 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include "MyExceptions.hpp"

class Span {
  private:
    std::list<int>     _elements;
    unsigned int       _size;
    unsigned int       _emptyElements;

  public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& other);
    Span& operator=(Span& other);

    const std::list<int>&   getElements() const;

    void  addNumber(int newElement);
    int   shortestSpan() const;
    int   longestSpan() const;
    template <typename T>
    void  addMultipleNumbers(T first, T last) {
      if (std::distance(first, last) > _emptyElements)
        throw SpanToSmallForArrayException();
      for (T it = first; it != last; it++)
        addNumber(*it);
}
};

#endif

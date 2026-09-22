/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:54:39 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/06 14:54:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <cstdlib>
# include <ctime>

template <class T>
class Array {
	private:
		T				*_elements;
		unsigned int	_arraySize;

	public:
		Array() {
			_elements = NULL;
			_arraySize = 0;
			std::cout << "Array: empty constructor" << std::endl;
		}

		Array(unsigned int n) : _elements(new T[n]), _arraySize(n){
			for (unsigned int i = 0; i < n; i++) {
				_elements[i] = T();
			}
			std::cout << "Array: unsigned int constructor" << std::endl;
		}

		Array(const Array& other) {
			_arraySize = other._arraySize;

			_elements = new T[_arraySize];
			for(size_t i = 0; i < _arraySize; i++) {
				_elements[i] = other._elements[i];
			}
			std::cout << "Array: Copy constructor" << std::endl;
		}

		Array&	operator=(const Array& other) {
			if (this == &other)
				return (*this);
			else {
				delete [] _elements;

				_arraySize = other._arraySize;
				_elements = new T[_arraySize];
				for(size_t i = 0; i < _arraySize; i++) {
					_elements[i] = other._elements[i];
				}
			}
			std::cout << "assignment operator overload" << std::endl;
			return (*this);
		}

		~Array() {
			delete[] _elements;
			std::cout << "Default destructor" << std::endl;
		}

		T&	operator[](unsigned int index) {
			if (index >= _arraySize)
				throw std::out_of_range("Index out of range");
			else
				return(_elements[index]);
		}

		unsigned int size() const {
			return (_arraySize);
		}
};

#endif

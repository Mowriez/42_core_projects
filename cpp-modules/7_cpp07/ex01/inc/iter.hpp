/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:52:21 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/05 23:52:21 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void iter(T* array, size_t length, F function) {
	for (size_t i = 0; i < length; i++) {
		function(array[i]);
	}
}

// template functions to show that an instantiated function template works as
// the third parameter of my iter-fct
template <typename T>
void printElement(T& element) {
	std::cout << element << std::endl;
}

template <>
void printElement<float>(float& element) {
	std::cout << "float: "<< element << std::endl;
}

#endif

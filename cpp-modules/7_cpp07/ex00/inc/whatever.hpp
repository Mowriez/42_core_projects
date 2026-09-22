/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:22:14 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/05 13:22:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
void	swap(T &variableA, T &variableB) {
	T temp = variableA;
	variableA = variableB;
	variableB = temp;
}

template <typename T>
T	min(T &variableA, T &variableB) {
	if (variableA < variableB)
		return variableA;
	else
		return variableB;
}

template <typename T>
T max(T &variableA, T &variableB) {
	if (variableA > variableB)
		return variableA;
	else
		return variableB;
}

#endif

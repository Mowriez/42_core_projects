/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:13:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/04 19:46:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
Serializer::Serializer() {
	std::cout << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(const Serializer &) {
	std::cout << "Serializer copy constructor" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &) {
	std::cout << "Serializer copy assignment operator overload" << std::endl;
	return (*this);
}

Serializer::~Serializer() {
	std::cout << "Serializer default destructor" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	serializedPtr = reinterpret_cast<uintptr_t>(ptr);
	return (serializedPtr);
}

Data*		Serializer::deserialize(uintptr_t raw) {
	Data*	deserializedInt = reinterpret_cast<Data*>(raw);
	return (deserializedInt);
}

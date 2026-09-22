/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:45:54 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/04 19:45:57 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int	main(void) {
	std::cout << std::endl << "----QUICK TEST TO SEE THAT (DE)SERIALIZING WORKS----"
			<< std::endl;
	Data dataTest;
	dataTest.exampleData = "I am example data";

	std::cout << dataTest.exampleData << std::endl << std::endl;
	std::cout << "ptr to dataTest before serializing: '"
				<< &dataTest << "'"<< std::endl << std::endl;
	std::cout << "serializing..." << std::endl << std::endl;
	uintptr_t serializedPtr = Serializer::serialize(&dataTest);
	std::cout << "uintptr_t representation of ptr: '" << serializedPtr << "'"
				<< std::endl << std::endl;
	std::cout << "deserializing..." << std::endl << std::endl;
	Data *DeserializedPtr = Serializer::deserialize(serializedPtr);
	std::cout << "ptr to dataTest after deserializing: '"
				<< DeserializedPtr << "'" << std::endl << std::endl;
	std::cout << "Example data after deserializing: " << DeserializedPtr->exampleData
				<< std::endl;
}

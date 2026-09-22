/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:22:14 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/05 17:22:54 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "../inc/iter.hpp"

std::string	sendPoemsPls(size_t i) {
	std::string retString = "In the realm of C++, where code finds its way,\n"
							"A template whispers, in the light of day.\n"
							"A vessel of patterns, a blueprint so fine,\n"
							"A dance of types, in a language design.\n"
							"In angle brackets, a promise unfolds,\n"
							"A template's tale, as the story's told.\n"
							"Generics abound, in a versatile trance,\n"
							"A template's magic, in the coder's dance.\n"
							"From classes to functions, it weaves its art,\n"
							"A flexible charm, where logic departs.\n"
							"A parametric dream, where types align,\n"
							"In the template's embrace, all codes entwine.\n";
	if (i <= retString.length())
		std::cout << retString.substr(0, i) << std::endl << std::endl;
	else
		std::cout << retString << std::endl << std::endl;
	return ("test");
}

void	capitalize(std::string &input) {
	std::string	output = input;
	for (size_t i = 0; i < output.length(); i++)
		output[i] = toupper(output[i]);
	std::cout << output << std::endl;
}



int main(void) {
	std::cout << "---Arr type: size_t, function type std::string---" << std::endl;
	size_t	sizeTArr[7] = {1, 15, 26, 10, 2000, 5, 0};
	iter(sizeTArr, sizeof(sizeTArr) / sizeof(size_t), sendPoemsPls);

	std::cout << "---Arr type: std::string, function type: void---" << std::endl;
	std::string stringArr[4] = {"test", "another test", "q231asdasf",
							"more different test"};
	iter(stringArr, sizeof(stringArr) / sizeof(std::string), capitalize);

	std::cout << "---Arr type: double, function type: void---" << std::endl;
	double	doubleArr[3] = {1.2, 3.4, 5.6};
	float	floatArr[3] = {1.2f, 3.4f, 5.6f};
	iter(doubleArr, sizeof(doubleArr) / sizeof(double), printElement<double>);
	iter(floatArr, sizeof(floatArr) / sizeof(float), printElement<float>);
}

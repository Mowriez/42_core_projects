/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:18:23 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/01 22:13:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../inc/MyExceptions.hpp"
#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
  try {
    if (argc != 2)
      throw MyBasicException();
    std::string input = static_cast<std::string>(argv[1]);
    checkInput(input);
    runRPNCalculation(input);
  }
  catch (std::exception &e) {
    std::cout << e.what();
  }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:50:01 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 10:08:24 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include "../inc/Exceptions.hpp"
#include "../inc/utils.hpp"

int main(int argc, char** argv) {
  try {
    checkInput(argc);
    std::string inputFilePath = static_cast<std::string>(argv[1]);
    BitcoinExchange bitExchange = BitcoinExchange(inputFilePath);
    bitExchange.processInput();
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
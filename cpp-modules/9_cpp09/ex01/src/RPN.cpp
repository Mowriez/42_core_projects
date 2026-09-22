/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:28:30 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/01 22:41:45 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

void  checkInput(std::string& input) {
  for(size_t i = 0; i < input.length(); i++) {
    if (!(isdigit(input[i]) || input[i] == '+' || input[i] == '-'
         || input[i] == '*' || input[i] == '/'  || input[i] == ' ')
         || (!isdigit(input[0]) && !(input[0] == '-') && !(input[0] == '+')))
      throw WrongFormatException(i, input);
  }

  size_t blockStart = 0;
  size_t blockEnd = 0;
  bool stop = false;
  while(1) {
    if (input.find(' ', blockStart) == std::string::npos) {
      stop = true;
      blockEnd = input.length();
    }
    else
      blockEnd = (input.find(' ', blockStart));
    std::string block = input.substr(blockStart , blockEnd - blockStart);
    checkBlock(block);
    if (stop)
      break;
    blockStart = blockEnd + 1;
  }
}

void  checkBlock(std::string& block) {
  for (size_t i = 0; i < block.length(); i++) {
    if ((block[i] == '+' || block[i] == '-'
         || block[i] == '*' || block[i] == '/')) {
        if (i != 0)
          throw WrongBlockFormatException(block);
      }
  }
}

void runRPNCalculation(std::string& input) {
  std::stack<int> RPNStack;
  size_t blockStart = 0;
  size_t blockEnd = 0;
  bool stop = false;
  int  result = 0;

  // std::cout << input << std::endl;
  while(true) {
    if (input.find(' ', blockStart) == std::string::npos) {
      stop = true;
      blockEnd = input.length();
    }
    else
      blockEnd = (input.find(' ', blockStart));
    std::string block = input.substr(blockStart , blockEnd - blockStart);
    if (block.empty()) {
      std::string msg = "multiple concurrent spaces or space at end of input";
      throw WrongBlockFormatException(msg);
    }
    manipulateStack(RPNStack, block, result);
    if (stop) {
      if (RPNStack.size() != 1) {
        std::string msg = "incorrect number of operators";
        throw WrongBlockFormatException(msg);
      }
      else {
      std::cout << "Result: |" << result << "|" << std::endl;
      break;
      }
    }
    blockStart = blockEnd + 1;
  }
}

void  manipulateStack(std::stack<int>& RPNStack, std::string& block, int& result) {
  int    firstNum;
  int    secondNum;

  if (block == "+" || block == "-" || block == "*" || block == "/") {
    if (RPNStack.size() < 2)
      throw WrongBlockFormatException(block);
    secondNum = RPNStack.top();
    RPNStack.pop();
    firstNum = RPNStack.top();
    RPNStack.pop();
    // std::cout << "first: " << firstNum << " second: " << secondNum << " operand: " << block << std::endl;
    if (block == "+")
      result = firstNum + secondNum;
    else if (block == "-")
      result = firstNum - secondNum;
    else if (block == "/")
      result = firstNum / secondNum;
    else if (block == "*")
      result = firstNum * secondNum;
    else
      throw WrongBlockFormatException(block);
    RPNStack.push(result);
   }
   else {
    RPNStack.push(atoi(block.c_str()));
   }
}

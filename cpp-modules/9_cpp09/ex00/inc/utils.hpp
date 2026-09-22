/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:55:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 10:31:01 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstdlib>
# include <map>
# include "../inc/Exceptions.hpp"

void  checkInput(int argc);
bool  checkFormat(std::string& line);

bool  checkDate(std::string& line);
bool  checkYear(std::string& date);
bool  checkMonth(std::string& date);
bool  checkDay(std::string& date);
bool  checkDate(std::string& date);
bool  checkExchangeRate(std::string& line);

int   extractDate(std::string& line);
void  printMap(std::map<int, double>& map);

void  checkBadInput(std::string& line);
void  checkValue(std::string& line);

#endif

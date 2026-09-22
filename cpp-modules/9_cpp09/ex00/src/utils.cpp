/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:56:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 11:25:59 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

void  checkInput(int argc) {
  if (argc <= 1)
    throw InputFileMissingException();
  if (argc > 2)
    throw TooManyArgsException();
  
}

bool  checkFormat(std::string& line) {
  if (line.length() < 12)
    return (false);
  if (line.find('-', 0) != 4 || line.find('-', 5) != 7 || line.find(',', 8) != 10)
    return (false);
  for (size_t i = 0; i != '\n'; i++) {
    if (!(line[i] == '-' || line[i] == ',' || line[i] == '.'
      || isdigit(static_cast<unsigned char>(line[i]))))
      return (false);
  }
  return (true);
}

bool  checkDate(std::string& line) {
  std::string date = line.substr(0, 10);
  if (!checkYear(date))
    return (false);
  if (!checkMonth(date))
    return (false);
  if (!checkDay(date))
    return (false);
  return (true);
}

bool  checkYear(std::string& date) {
  for (size_t i = 0; i < 4; i++) {
    if (!isdigit(date[i]))
      return (false);
  }
  return (true);
}

bool  checkMonth(std::string& date) {
  if (!(isdigit(date[5]) && isdigit(date[6])))
      return (false);
  int month = atoi(date.substr(5, 2).c_str());
  if (month < 1 || month > 12)
    return (false);
  return (true);
}

bool  checkDay(std::string& date) {
  if (!(isdigit(date[8]) && isdigit(date[9])))
      return (false);
  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());
  if (day < 1)
    return (false);
  if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 
      || month == 10 || month == 12) && day > 31)
    return (false);
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return (false);
  if (month == 2 && (((year % 4 == 0) && day > 29) 
                || ((year % 4 != 0) && day > 28)))
    return (false);
  return (true);
}

bool  checkExchangeRate(std::string& line) {
  std::string exchangeRateString = line.substr(11, line.length() - 11);

  size_t periodCount = 0;
  for (size_t i = 0; i < exchangeRateString.length(); i++) {
    if (!(isdigit(exchangeRateString[i]) || exchangeRateString[i] == '.'))
      return (false);
    if (exchangeRateString[i] == '.') {
      periodCount++;
      if (periodCount > 1)
        return (false);
    }
  }
  return (true);
}

int extractDate(std::string& line) {
  std::string year = line.substr(0, 4);
  std::string month = line.substr(5, 2);
  std::string day = line .substr(8, 2);
  std::stringstream ss;

  ss << year << month << day;
  int date = atoi(ss.str().c_str());
  return (date);
}

void  printMap(std::map<int, double>& map) {
  for (std::map<int, double>::iterator it = map.begin(); it != map.end(); it++)
    std::cout << it->first << " | " << it->second << std::endl;
}

void  checkBadInput(std::string& line) {
  if (line == "date | value")
    return ;
  if (line.length() < 14)
    throw InvalidFormatException(line);
  for (size_t i = 0; i < line.length(); i++) {
    if (!(isdigit(line[i]) || line[i] == '|' || line[i] == '-' 
        || line[i] == ' ' || line[i] == '.'))
      throw InvalidFormatException(line);
  }
  if (line.find('-', 0) != 4 || line.find('-', 5) != 7 || line.find('|', 0) != 11)
    throw InvalidFormatException(line);
  if (!checkDate(line))
    throw InvalidDateException(line);
  checkValue(line);
}

void  checkValue(std::string& line) {
  if (line.find('|', 0) != 11)
    throw InvalidFormatException(line);
  std::string valueString = line.substr(13, line.length() - 13);
  int periodCount = 0;
  for (size_t i = 0; i != valueString.length(); i++) {
    if (!(isdigit(valueString[i]) || valueString[i] == '.' || valueString[i] == '-'))
      throw InvalidFormatException(valueString);
    if (valueString[i] == '.') {
      periodCount++;
      if (periodCount > 1)
        throw InvalidFormatException(valueString);
    }
  }
  double value = strtod(valueString.c_str(), NULL);
  if (value == 0 && valueString != "0")
    throw InvalidFormatException(valueString);
  if (value < 0)
    throw NotPositiveNumberException();
  if (value > 1000)
    throw TooLargeNumberException();
}

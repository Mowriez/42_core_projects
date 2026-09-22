/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:38:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 15:07:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string& inputFilePath)
  : _dataBaseFilePath("./db/data.csv"), _inputFilePath(inputFilePath) {
  checkDataBaseIntegrity();
  parseDataBaseFile();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  _dataBaseFilePath = other._dataBaseFilePath;
  _dataBase = other._dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    _dataBaseFilePath = other._dataBaseFilePath;
    _dataBase = other._dataBase;
  }
  return (*this);
}

void  BitcoinExchange::checkDataBaseIntegrity() {
  std::ifstream dataBaseFile(_dataBaseFilePath.c_str());
  if (!dataBaseFile.is_open())
    throw DataBaseFileAccessException();

  std::string lineContent;
  int         lineNum = 1;
  while (getline(dataBaseFile, lineContent)) {
    if (lineContent == "date,exchange_rate") {
      lineNum++;
      continue;
    }
    if (!checkFormat(lineContent)) {
      dataBaseFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    if (!checkDate(lineContent)) {
      dataBaseFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    if (!checkExchangeRate(lineContent)) {
      dataBaseFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    lineNum++;
  }
  dataBaseFile.close();
}

void  BitcoinExchange::parseDataBaseFile() {
  std::ifstream dataBaseFile(_dataBaseFilePath.c_str());

  if (!dataBaseFile.is_open())
        throw DataBaseFileAccessException();

  std::string lineContent;
  int         date;
  double      conversionRate;
  while (getline(dataBaseFile, lineContent)) {
    if (lineContent == "date,exchange_rate")
      continue;
    date = extractDate(lineContent);
    conversionRate = strtod(lineContent.substr(11, lineContent.length() - 11).c_str(), NULL);
    _dataBase[date] = conversionRate;
  }
  dataBaseFile.close();
  if (_dataBase.empty())
    throw DataBaseEmptyException();
}

void  BitcoinExchange::processInput() {
  std::ifstream inputFile(_inputFilePath.c_str());
  if (!inputFile.is_open())
        throw InputFileAccessException();
  std::string line;
  while (getline(inputFile, line)) {
    try {
      checkBadInput(line);
      parseRequestLine(line);
    }
    catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  inputFile.close();
}

void  BitcoinExchange::parseRequestLine(std::string& line) {
  if (line == "date | value")
    return;
  int date = extractDate(line);
  double value = strtod(line.substr(12, line.length() - 12).c_str(), NULL);
  if (handleEarlyAndLateDates(line, date, value))
    return ;

  std::map<int, double>::iterator lookUpIterator = _dataBase.lower_bound(date);
  if (lookUpIterator->first == date)
    std::cout << line.substr(0, 10) << " => " << value << " = "
              << value * lookUpIterator->second << std::endl;
  else {
    lookUpIterator--;
    std::cout << line.substr(0, 10) << " => " << value << " = "
              << value * lookUpIterator->second
              << " (value from: " << lookUpIterator->first << ")" << std::endl;
  }
}

bool  BitcoinExchange::handleEarlyAndLateDates(std::string& line, int& date, double& value) {
  std::map<int, double>::iterator it = _dataBase.begin();
  double  earliestDate = it->first;
  double  latestDate = it->first;

  for (it = _dataBase.begin(); it != _dataBase.end(); it++) {
    if (it->first < earliestDate)
      earliestDate = it->first;
    if (it->first > latestDate)
      latestDate = it->first;
  }
  if (date < earliestDate) {
    std::cout << line.substr(0, 10) << " => " << value 
              << " = 0 (date before earliest database entry)" << std::endl;
    return (true);
  }
  else if (date > latestDate) {
    std::cout << line.substr(0, 10) << " => " << value << " = "
              << std::fixed << std::setprecision(2) << value * _dataBase[latestDate] 
              << " (date after latest database entry)" << std::endl;
    return (true);
  }
  return (false);
}

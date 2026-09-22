/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:30:35 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 11:28:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <map>
# include "../inc/Exceptions.hpp"
# include "../inc/utils.hpp"

class BitcoinExchange {
  private:
    std::string                   _dataBaseFilePath;
    std::string                   _inputFilePath;
    std::map<int, double> _dataBase;

  public:
    BitcoinExchange(std::string& inputFilePath);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void  checkDataBaseIntegrity();
    void  parseDataBaseFile();

    void  processInput();
    void  parseRequestLine(std::string& line);
    bool  handleEarlyAndLateDates(std::string& line, int& date, double& value);
};

#endif

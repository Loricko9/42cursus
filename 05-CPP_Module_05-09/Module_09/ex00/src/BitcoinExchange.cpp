/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:50:38 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/22 17:56:25 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	base("data.csv");
	if (!base.is_open())
		throw OpenFileException();
	std::string		res;
	std::getline(base, res);
	if (res != "date,exchange_rate") {
		base.close();
		throw OpenFileException();
	}
	size_t		pos_virg;
	std::string	str_double;
	while (std::getline(base, res)) {
		pos_virg = res.find(',');
		if (pos_virg == std::string::npos) {
			base.close();
			throw OpenFileException();
		}
		str_double = res.substr(pos_virg + 1);
		data_base.insert(std::pair<std::string, double>(res.substr(0, pos_virg), strtod(str_double.c_str(), NULL)));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
	:data_base(src.data_base)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		data_base = rhs.data_base;
	return (*this);
}

std::ostream&	operator<<(std::ostream &o, const BitcoinExchange &rhs)
{
	std::map<std::string, double>::const_iterator	it = rhs.getBegin();
	std::map<std::string, double>::const_iterator	end = rhs.getEnd();
	while (it != end) {
		std::cout << (*it).first << " --> " << (*it).second << std::endl;
		it++;
	}
	return (o);
}

BitcoinExchange::~BitcoinExchange()
{
	
}

std::map<std::string, double>::const_iterator	BitcoinExchange::getBegin() const
{
	return (data_base.begin());
}

std::map<std::string, double>::const_iterator	BitcoinExchange::getEnd() const
{
	return (data_base.end());
}


std::string	BitcoinExchange::extractDate(std::string &str, double *nb) const
{
	size_t	pos = str.find('|');
	if (pos == std::string::npos)
		throw BadInputException();

	std::string	date = str.substr(0, pos);
	checkDate(date);
	std::string	str_nb = str.substr(pos + 1);
	checkNb(str_nb);
	
	double		nb_temp = strtod(str_nb.c_str(), NULL);
	if (nb_temp < 0.0)
		throw PosNumberException();
	if (nb_temp > 1000.0)
		throw LargeNumberException();
	if (nb)
		*nb = nb_temp;

	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	str_nb.erase(std::remove(str_nb.begin(), str_nb.end(), ' '), str_nb.end());
	std::cout << date << " => " << str_nb;
	return (date);
}

void	BitcoinExchange::checkDate(const std::string &str) const
{
	std::istringstream	iss(str);
	int		year, month, day;
	char	delimiter;
	
	iss >> year >> delimiter >> month >> delimiter >> day;
	if (iss.fail() || delimiter != '-')
		throw BadInputException();
	if (year < 2009 || year > 2023 || month <= 0 || month > 12 || day <= 0 || day > 31
		|| (year == 2009 && month == 1 && day == 1))
		throw BadInputException();
}

void	BitcoinExchange::checkNb(std::string &str) const
{
	if (str.empty())
		throw BadInputException();
	int i = 0;
	int	size = str.size();
	
	while (str[i] == ' ' && i < size)
		i++;
	if (i == size)
		throw BadInputException();
	while (i < size) {
		if (!isdigit(str[i]))
			throw BadInputException();
		i++;
	}
}

double	BitcoinExchange::getValue(std::string &date)
{
	std::istringstream	iss(date);
	std::stringstream	ss;

	int		year, month, day;
	char	delimiter;
	iss >> year >> delimiter >> month >> delimiter >> day;
	ss << fixnb(year) << "-" << fixnb(month) << "-" << fixnb(day);
	while (data_base.find(ss.str()) == data_base.end()) {
		day--;
		if (day == 0) {
			day = 31;
			month--;
			if (month == 0) {
				month = 12;
				year--;
			}
		}
		ss.str("");
		ss.clear();
		ss << fixnb(year) << "-" << fixnb(month) << "-" << fixnb(day);
	}
	return (data_base[ss.str()]);
}

const std::string	BitcoinExchange::fixnb(int nb) const
{
	std::stringstream	ss;
	if (nb < 10)
		ss << "0" << nb;
	else
		ss << nb;
	std::string	res(ss.str());
	return (res);
}

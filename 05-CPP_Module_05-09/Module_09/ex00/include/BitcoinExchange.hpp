/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:46:32 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/22 17:52:49 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>

class	BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange&	operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	class OpenFileException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Error : can't open/read data_base !");
		}
	};
	class PosNumberException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Error : not a positive number.");
		}
	};
	class BadInputException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Error : bad input => ");
		}
	};
	class LargeNumberException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Error : too large number");
		}
	};

	std::map<std::string, double>::const_iterator	getBegin() const;
	std::map<std::string, double>::const_iterator	getEnd() const;
	std::string										extractDate(std::string &str, double *nb) const;
	double											getValue(std::string &date);
	void											checkDate(const std::string &str) const;
private:
	std::map<std::string, double>	data_base;

	void				checkNb(std::string &str) const;
	const std::string	fixnb(int nb) const;
};

std::ostream&	operator<<(std::ostream &o, const BitcoinExchange &rhs);

#endif

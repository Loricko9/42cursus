/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:53:30 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 17:38:27 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	
}

void	ScalarConverter::convert(std::string arg)
{
	if (arg.empty())
		std::cout << "Error : Argument empty" << std::endl;
	else if (is_char(arg)) 
		print_char(arg);
	else if (is_int(arg))
		print_int(arg);
	else if (is_float(arg))
		print_float(arg);
	else if (is_double(arg))
		print_double(arg);
	else
		std::cout << "Error : Bad Argument" << std::endl;
}

bool	ScalarConverter::is_char(const std::string &arg)
{
	if (arg.length() == 1 && isprint(arg[0]) && !isdigit(arg[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::is_int(const std::string &arg)
{
	for (int i = 0, len = arg.length(); i < len; i++)
	{
		if ((arg[i] == '-' && i != 0) || !isprint(arg[i]) || (!isdigit(arg[i]) && (i != 0 || arg[i] == '.')))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::is_float(const std::string &arg)
{
	if (arg == "-inff" || arg == "+inff" || arg == "nanf")
		return (true);
	int	trig_d = 0;
	int	trig_p = 0;
	for (int i = 0, len = arg.length(); i < len; i++)
	{
		if ((arg[i] == '-' && i != 0) || !isprint(arg[i]) || (arg[i] == 'f' && i != len - 1) ||
			(!isdigit(arg[i]) && i != 0 && arg[i] != '.' && arg[i] != 'f'))
			return (false);
		if (arg[i] == '.')
			trig_p++;
		if (isdigit(arg[i]))
			trig_d++;
	}
	if (trig_d == 0 || trig_p != 1 || arg[arg.length() - 1] != 'f')
		return (false);
	return (true);
}

bool	ScalarConverter::is_double(const std::string &arg)
{
	if (arg == "-inf" || arg == "+inf" || arg == "nan")
		return (true);
	int	trig_d = 0;
	int	trig_p = 0;
	for (int i = 0, len = arg.length(); i < len; i++)
	{
		if ((arg[i] == '-' && i != 0) || !isprint(arg[i]) ||
			(!isdigit(arg[i]) && i != 0 && arg[i] != '.'))
			return (false);
		if (arg[i] == '.')
			trig_p++;
		if (isdigit(arg[i]))
			trig_d++;
	}
	if (trig_d == 0 || trig_p != 1)
		return (false);
	return (true);
}

void	ScalarConverter::print_char(const std::string &arg)
{
	char	c = arg[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void	ScalarConverter::print_int(const std::string &arg)
{
	long	nb = strtol(arg.c_str(), NULL, 10);
	if (nb < 32 || nb > 127 || !isprint(nb))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
	if (nb > __INT_MAX__ || nb < -__INT_MAX__ - 1)
		std::cout << "int: out of range" << std::endl;
	else
		std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}

void	ScalarConverter::print_float(const std::string &arg)
{
	float	nb = atof(arg.c_str());
	if (arg == "nanf" || arg == "+inff" || arg == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << arg.substr(0, arg.length() - 1) << std::endl;
	}
	else {
		if (nb >= 32 && nb <= 127 && isprint(nb))
			std::cout << "char: " << static_cast<char>(nb) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (static_cast<long>(nb) > __INT_MAX__ || static_cast<long>(nb) < -__INT_MAX__ - 1)
			std::cout << "int: out of range" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nb) << std::endl;
		if (fmod(nb, 1) == 0) {
			std::cout << "float: " << nb << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
		}
		else {
			std::cout << "float: " << nb << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(nb) << std::endl;
		}
	}
}

void	ScalarConverter::print_double(const std::string &arg)
{
	double	nb = strtod(arg.c_str(), NULL);
	if (arg == "nan" || arg == "+inf" || arg == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << "f" << std::endl;
		std::cout << "double: " << arg << std::endl;
	}
	else {
		if (nb >= 32 && nb <= 127 && isprint(nb))
			std::cout << "char: " << static_cast<char>(nb) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (static_cast<long>(nb) > __INT_MAX__ || static_cast<long>(nb) < -__INT_MAX__ - 1)
			std::cout << "int: out of range" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nb) << std::endl;
		if (fmod(nb, 1) == 0) {
			std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
			std::cout << "double: " << nb << ".0" << std::endl;
		}
		else {
			std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
			std::cout << "double: " << nb << std::endl;
		}
	}
}

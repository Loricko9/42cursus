/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:54:30 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 17:37:07 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter&	operator=(const ScalarConverter &rhs);
	~ScalarConverter();
	
	static void	convert(std::string arg);
	virtual	void	instance() = 0;
private:
	static bool	is_char(const std::string &arg);
	static bool	is_int(const std::string &arg);
	static bool	is_float(const std::string &arg);
	static bool	is_double(const std::string &arg);

	static void	print_char(const std::string &arg);
	static void	print_int(const std::string &arg);
	static void	print_float(const std::string &arg);
	static void	print_double(const std::string &arg);
};

#endif

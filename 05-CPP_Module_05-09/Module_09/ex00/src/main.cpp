/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:46:14 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/01 18:34:43 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error : Invalid number of Argument !" << std::endl;
		return (1);
	}
	std::string	file_test(av[1]);
	if (file_test.find(".csv") != file_test.size() - 4) {
		std::cerr << "Error : file must be in .csv extension !" << std::endl;
		return (1);
	}
	std::ifstream	f_in(av[1]);
	if (!f_in.is_open()) {
		std::cerr << "Error : Can't open the file !" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange	base;
		std::string		res;
		while (std::getline(f_in, res)) {
			try {
				double		val;
				std::string	date = base.extractDate(res, &val);
				double		coef = base.getValue(date);
				std::cout << " = " << coef * val << std::endl;
			}
			catch (BitcoinExchange::BadInputException &e) {
				std::cout << e.what() << res << std::endl;
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

		}
		
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	f_in.close();
}

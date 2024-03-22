/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:46:14 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/22 10:56:49 by lle-saul         ###   ########.fr       */
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
	std::ifstream	f_in(av[1]);
	if (!f_in.is_open()) {
		std::cerr << "Error : Can't open the file !" << std::endl;
		return (1);
	}
	
}

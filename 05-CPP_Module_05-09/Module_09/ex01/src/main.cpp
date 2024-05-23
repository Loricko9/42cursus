/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:46:05 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/01 18:14:47 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Error : Invalid number of argument" << std::endl;
		return (1);
	}
	try {
		RPN	rpn;
		for (int i = 0, size = strlen(av[1]); i < size; i += 2) {
			if (isdigit(av[1][i]))
				rpn.addNb(av[1][i] - 48);
			else if (av[1][i] == '+' || av[1][i] == '*' || av[1][i] == '-' || av[1][i] == '/')
				rpn.execCalc(av[1][i]);
			else {
				throw RPN::BadInputException();
			}
			if (av[1][i + 1] != ' ' && av[1][i + 1] != '\0') {
				throw RPN::BadInputException();
			}
		}
		if (rpn.getSize() == 1)
			std::cout << rpn.getNb() << std::endl;
		else
			throw RPN::BadExpressionException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

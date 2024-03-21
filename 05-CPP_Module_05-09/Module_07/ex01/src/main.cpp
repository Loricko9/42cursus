/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:30:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 10:28:52 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void ) {
	int	tab1[5] = {89, 56, 23, 12, 4};
	iter<int>(tab1, 5, print);
	std::cout << std::endl << "----------------------------------------" << std::endl;

	char tab2[6] = {'a', 'z', 'e', 'r', 't', 'y'};
	iter<char>(tab2, 6, print);
	std::cout << std::endl << "----------------------------------------" << std::endl;

	double tab3[5] = {89.3, 56.2, 75.42, 12.09, 87.59};
	iter<double>(tab3, 5, print);
	std::cout << std::endl << "----------------------------------------" << std::endl;

	std::string	tab4[5];
	tab4[0] = "salut";
	tab4[1] = "comment";
	tab4[2] = "tu";
	tab4[3] = "va";
	tab4[4] = "?";
	iter<std::string>(tab4, 5, print);
	std::cout << std::endl << "----------------------------------------" << std::endl;
}
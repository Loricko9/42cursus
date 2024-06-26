/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:56:52 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/30 12:26:14 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int>	test1(5);
	for (unsigned int i = 0, nb = 56; i < test1.size(); i++, nb++)
		test1[i] = nb;
	for (unsigned int i = 0; i < test1.size(); i++)
		std::cout << test1[i] << " " << std::flush;
	std::cout << std::endl;
	Array<int>	test2(test1);
	for (unsigned int i = 0; i < test2.size(); i++)
		std::cout << test2[i] << " " << std::flush;
	std::cout << std::endl;
	Array<int>	test3;
	test3 = test2;
	for (unsigned int i = 0; i < test3.size(); i++)
		std::cout << test3[i] << " " << std::flush;
	std::cout << std::endl;
	try {
		test1[-2] = 8;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		test1[89] = 8;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    
	std::cout << "----------------------------------------" << std::endl;
	Array<char>	test4(10);
	for (unsigned int i = 0, nb = 97; i < test4.size(); i++, nb++)
		test4[i] = nb;
	for (unsigned int i = 0; i < test4.size(); i++)
		std::cout << test4[i] << " " << std::flush;
	std::cout << std::endl;
	Array<char>	test5(test4);
	for (unsigned int i = 0; i < test5.size(); i++)
		std::cout << test5[i] << " " << std::flush;
	std::cout << std::endl;
	try {
		test5[-2] = 42;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		test5[89] = 42;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	test1 = test2;
	for (unsigned int i = 0; i < test1.size(); i++)
		std::cout << test1[i] << " " << std::flush;
	std::cout << std::endl;
}
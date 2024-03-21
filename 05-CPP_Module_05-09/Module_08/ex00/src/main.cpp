/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:30:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 13:36:07 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main( void ) 
{
	std::vector<int>	test1(10, 25);
	std::vector<int>	test2(10, 25);
	test1[6] = 32;
	try
	{
		easyfind(test1, 32);
		std::cout << "Val Found !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(test2, 32);
		std::cout << "Val Found !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::list<int>	test3(10, 25);
	std::list<int>	test4(10, 25);
	test3.assign(7, 32);
	try
	{
		easyfind(test3, 32);
		std::cout << "Val Found !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(test4, 32);
		std::cout << "Val Found !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
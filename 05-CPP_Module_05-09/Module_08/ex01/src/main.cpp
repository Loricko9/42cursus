/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:30:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:56 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "---------------------------------------" << std::endl;
	
	try {
		Span sp2(10000);
		std::list<int>	temp(10000);
		std::srand(time(NULL));
		std::generate(temp.begin(), temp.end(), std::rand);
	
		sp2.addNumber(temp.begin(), temp.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	std::cout << "---------------------------------------" << std::endl;
	
	try {
		Span sp2(20);
		sp2.addNumber(6);
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		Span sp2(20);
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		Span sp2(1);
		sp2.addNumber(6);
		sp2.addNumber(60);
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}
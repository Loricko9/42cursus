/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:22 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 11:47:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	test1("test1", 1);
		std::cout << test1 << std::endl;
		test1.Decrement();
		test1.Decrement();
		std::cout << test1 << std::endl;
		test1.Increment();
		test1.Increment();
		std::cout << test1 << std::endl;
		test1.Increment();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	try
	{
		Bureaucrat	test2("test2", 1236);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:22 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	test1("test1", 1);
		Form		form1("form1", 68, 20);
		std::cout << form1 << std::endl;
		test1.signForm(form1);
		std::cout << form1 << std::endl;
		test1.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	try
	{
		Bureaucrat	test2("test2", 93);
		Form		form2("form2", 2, 89);
		std::cout << form2 << std::endl;
		test2.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	try {
		Form		form2("form2", 0, 89);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
}

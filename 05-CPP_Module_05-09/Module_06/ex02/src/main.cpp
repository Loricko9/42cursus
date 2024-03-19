/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 18:48:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


Base*	generate()
{
	Base	*base;
	std::srand(std::time(NULL));
	int i = std::rand();
	if (i % 3 == 0) {
		std::cout << "Class type A created !" << std::endl;
		base = new A();
	}
	else if (i % 3 == 1) {
		std::cout << "Class type B created !" << std::endl;
		base = new B();
	}
	else {
		std::cout << "Class type C created !" << std::endl;
		base = new C();
	}
	return (base);
}

void	identify(Base *p)
{
		A	*test1 = dynamic_cast<A *>(p);
		B	*test2 = dynamic_cast<B *>(p);
		C	*test3 = dynamic_cast<C *>(p);
		if (test1 != NULL)
			std::cout << "Actual type identified : A" << std::endl;
		else if (test2 != NULL)
			std::cout << "Actual type identified : B" << std::endl;
		else if (test3 != NULL)
			std::cout << "Actual type identified : C" << std::endl;
		else
			std::cout << "No Type identified..." << std::endl;
}

void	identify(Base &p)
{
	try {
		A	&test1 = dynamic_cast<A &>(p);
		(void)test1;
		std::cout << "Actual type identified : A" << std::endl;
		return ;
	}
	catch (std::exception &bc) {
		(void)bc;
	}
	try {
		B	&test2 = dynamic_cast<B &>(p);
		(void)test2;
		std::cout << "Actual type identified : B" << std::endl;
		return ;
	}
	catch (std::exception &bc) {
		(void)bc;
	}
	try {
		C	&test3 = dynamic_cast<C &>(p);
		(void)test3;
		std::cout << "Actual type identified : C" << std::endl;
		return ;
	}
	catch (std::exception &bc) {
		std::cout << "No Type identified..." << std::endl;
	}
}

int	main()
{
	Base	*base = generate();
	identify(base);
	identify(*base);
	identify(NULL);
	delete base;
}

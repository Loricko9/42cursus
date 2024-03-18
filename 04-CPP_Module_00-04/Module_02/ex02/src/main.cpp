/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:30:03 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/15 08:48:47 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed c(23.96f);
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const d(Fixed(53.28f) / Fixed(50));
	Fixed z(0);
	
	
	std::cout << "test1 : " << d << std::endl;
	if (z != a)
		std::cout << "testdiff" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:30:03 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/15 10:01:06 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point	a(1.2f, 1.2f);
	Point	b(3.86f, 7.56f);
	Point	c(9.0f, 5.0f);
	Point	P(2.1f, 2.4f);
	
	if (bsp(a, b, c, P))
		std::cout << "Le point est dedans" << std::endl;
	else
		std::cout << "Le point est PAS dedans" << std::endl;
}


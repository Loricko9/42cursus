/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:29:12 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 18:35:44 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	:RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
	:RawBits(i << Virgbit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
	:RawBits(roundf(f * (1 << Virgbit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &rhc)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhc)
		RawBits = rhc.getRawBits();
	return(*this);
}

std::ostream& operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

int	Fixed::getRawBits() const
{
	return (RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	RawBits = raw;
}

int	Fixed::toInt() const
{
	return (getRawBits() >> Virgbit);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(getRawBits()) / (1 << Virgbit));
}

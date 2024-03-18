/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:29:12 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 20:23:34 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	:RawBits(0)
{

}

Fixed::Fixed(const int i)
	:RawBits(i << Virgbit)
{

}

Fixed::Fixed(const float f)
	:RawBits(roundf(f * (1 << Virgbit)))
{
	
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{
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
	return (static_cast<float>(RawBits) / (1 << Virgbit));
}

Fixed&	Fixed::operator=(const Fixed &rhc)
{
	if (this != &rhc)
		RawBits = rhc.getRawBits();
	return(*this);
}

std::ostream& operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	if (getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	if (getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	if (getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	if (getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	if (getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	if (getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed	res(toFloat() + rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed	res(toFloat() - rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed	res(toFloat() * rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed	res(toFloat() / rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	RawBits++;
	return (temp);
}

Fixed&	Fixed::operator++(void)
{
	RawBits++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	RawBits--;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	RawBits--;
	return (*this);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

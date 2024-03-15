/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:28:58 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 19:48:02 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CPP
#define FIXED_CPP

#include <iostream>

class	Fixed
{
public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(const int i);
	Fixed(const float f);
	Fixed&	operator=(const Fixed &rhs);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs);
	Fixed	operator-(const Fixed &rhs);
	Fixed	operator*(const Fixed &rhs);
	Fixed	operator/(const Fixed &rhs);
	
	Fixed	operator++(int); //post
	Fixed&	operator++(void); //pre
	Fixed	operator--(int); //post
	Fixed&	operator--(void); //pre

	static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max(const Fixed &a, const Fixed &b);
private:
	int					RawBits;
	static const int	Virgbit = 8;
};

std::ostream& operator<<(std::ostream &o, Fixed const &i);

#endif
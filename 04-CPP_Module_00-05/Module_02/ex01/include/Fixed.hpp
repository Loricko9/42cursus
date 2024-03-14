/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:28:58 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 18:27:52 by lle-saul         ###   ########.fr       */
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
private:
	int					RawBits;
	static const int	Virgbit = 8;
};

std::ostream& operator<<(std::ostream &o, Fixed const &i);

#endif
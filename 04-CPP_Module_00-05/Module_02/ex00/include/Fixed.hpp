/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:28:58 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 13:50:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CPP
#define FIXED_CPP

class	Fixed
{
public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed&	operator=(const Fixed &rhs);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const raw);
private:
	int					RawBits;
	static const int	bit = 8;
};

#endif
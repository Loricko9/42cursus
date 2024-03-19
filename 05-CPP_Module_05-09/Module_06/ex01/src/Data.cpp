/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:30 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 18:06:38 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
	:i(0)
{
	
}

Data::Data(int nb)
	:i(nb)
{
	
}

Data::Data(const Data &src)
	:i(src.i)
{

}

Data&	Data::operator=(const Data &rhs)
{
	if (this != &rhs)
		i = rhs.i;
	return (*this);
}

Data::~Data()
{
	
}

int	Data::getI()
{
	return (i);
}

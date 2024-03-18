/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:19:37 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 21:20:17 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	:AMateria("ice")
{

}

Ice::Ice(const Ice &src)
	:AMateria("ice")
{
	(void)src;
}

Ice&	Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

Ice::~Ice()
{

}

AMateria*	Ice::clone() const
{
	AMateria*	clone = new Ice();
	return (clone);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}

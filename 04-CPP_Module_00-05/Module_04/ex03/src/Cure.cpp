/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:28:52 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 21:19:30 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure")
{

}

Cure::Cure(const Cure &src)
	:AMateria("cure")
{
	(void)src;

}

Cure&	Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

Cure::~Cure()
{

}

AMateria*	Cure::clone() const
{
	AMateria*	clone = new Cure();
	return (clone);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

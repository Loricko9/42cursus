/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:17:55 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 21:19:42 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	:type("")
{

}

AMateria::AMateria(const std::string &type)
	:type(type)
{

}

AMateria::AMateria(const AMateria &src)
	:type(src.type)
{

}

AMateria&	AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

AMateria::~AMateria()
{

}
const std::string&	AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Materia " << type << " use on " << target.getName() << std::endl;
}

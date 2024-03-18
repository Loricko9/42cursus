/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:33:57 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 12:03:19 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
	:type("")
{
	std::cout << "Default Contructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(std::string str)
	:type(str)
{
	std::cout << "Name Contructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
	:type(src.type)
{
	std::cout << "Copy Contructor AAnimal called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor AAnimal called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (type);
}

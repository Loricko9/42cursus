/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:26 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:48:26 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:type("Default")
{
	std::cout << "Default Contructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string str)
	:type(str)
{
	std::cout << "Name Contructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
	:type(src.type)
{
	std::cout << "Copy Contructor WrongAnimal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makesound call" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

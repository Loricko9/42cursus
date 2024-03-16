/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:33:57 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:51:12 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	:type("")
{
	std::cout << "Default Contructor Animal called" << std::endl;
}

Animal::Animal(std::string str)
	:type(str)
{
	std::cout << "Name Contructor Animal called" << std::endl;
}

Animal::Animal(const Animal &src)
	:type(src.type)
{
	std::cout << "Copy Contructor Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makesound call" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}

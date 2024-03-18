/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:34:16 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:21:02 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal("Dog")
{
	std::cout << "Default Contructor Dog called" << std::endl;
}

Dog::Dog(const Dog &src)
	:Animal(src.type)
{
	std::cout << "Copy Contructor Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf !" << std::endl;
}

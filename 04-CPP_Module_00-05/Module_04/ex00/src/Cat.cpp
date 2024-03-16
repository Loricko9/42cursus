/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:34:05 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:20:09 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal("Cat")
{
	std::cout << "Default Contructor Cat called" << std::endl;
}

Cat::Cat(const Cat &src)
	:Animal(src.type)
{
	std::cout << "Copy Contructor Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meoww..." << std::endl;
}

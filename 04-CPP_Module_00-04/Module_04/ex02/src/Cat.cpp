/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:34:05 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 12:17:18 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:AAnimal("Cat"), _Brain(new Brain)
{
	std::cout << "Default Contructor Cat called" << std::endl;
}

Cat::Cat(const Cat &src)
	:AAnimal(src.type), _Brain(new Brain(*src._Brain))
{
	std::cout << "Copy Contructor Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		_Brain = new Brain(*rhs._Brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _Brain;
	std::cout << "Destructor Cat called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meoww..." << std::endl;
}

void	Cat::addIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		_Brain->addSingleIdea(idea, i);
	std::cout << type << " have an idea !" << std::endl;
}

void	Cat::think()
{
	_Brain->getIdea();
}

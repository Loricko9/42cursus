/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:34:16 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 12:17:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:AAnimal("Dog"), _Brain(new Brain)
{
	std::cout << "Default Contructor Dog called" << std::endl;
}

Dog::Dog(const Dog &src)
	:AAnimal(src.type), _Brain(new Brain(*src._Brain))
{
	std::cout << "Copy Contructor Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		_Brain = new Brain(*rhs._Brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "Destructor Dog called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf !" << std::endl;
}

void	Dog::addIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		_Brain->addSingleIdea(idea, i);
	std::cout << type << " have an idea !" << std::endl;
}

void	Dog::think()
{
	_Brain->getIdea();
}

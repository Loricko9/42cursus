/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:32 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:42:34 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal("WrongCat")
{
	std::cout << "Default Contructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
	:WrongAnimal(src.type)
{
	std::cout << "Copy Contructor WrongCat called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meoww..." << std::endl;
}

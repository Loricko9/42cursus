/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:25:15 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 18:00:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Contructor Brain called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	std::cout << "Copy Contructor Brain called" << std::endl;
}

Brain& Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}	
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;

}

void	Brain::addSingleIdea(std::string &str, int i)
{
	if (i < 100 && i >= 0)
		ideas[i] = str;
}

void	Brain::getIdea()
{
	std::cout << ideas[0] << std::endl;
	std::cout << ideas[1] << std::endl;
	std::cout << ideas[10] << std::endl;
}

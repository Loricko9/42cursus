/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:53:01 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 21:20:32 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		mem[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (mem[i] != NULL)
				delete mem[i];
			mem[i] = rhs.mem[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (mem[i] != NULL)
			delete mem[i];
	}
}

void	MateriaSource::learnMateria(AMateria *Materia)
{
	if (Materia == NULL)
		return ;
	AMateria	*Copy(Materia);
	int i = 0;
	for (; i < 4; i++)
	{
		if (mem[i] == NULL) {
			mem[i] = Copy;
			break;
		}	
	}
	if (i == 4)
		std::cout << "MateriaSource full !" << std::endl;
	else
		std::cout << "Materia " << Materia->getType() << " add in MateriaSource" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string &type)
{
	AMateria	*temp = NULL;
	for (int i = 3; i >= 0; i--)
	{
		if (mem[i] != NULL && type == mem[i]->getType()) {
			temp = mem[i];
			mem[i] = NULL;
			return (temp);
		}
	}
	std::cout << "No correspondence found in the MateriaSource !" << std::endl;
	return (NULL);
}

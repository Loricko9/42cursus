/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:51:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/26 18:21:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	:name("")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &str)
	:name(str)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &src)
	:name(src.name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	*this = src;
}

Character&	Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			if (rhs.inventory[i] != NULL)
				inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

const std::string&	Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	int i = 0;
	for (; i < 4; i++)
	{
		if (inventory[i] == m) {
			std::cout << "Already have this Materia in the Inventory !" << std::endl;
			return ;
		}
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break;
		}	
	}
	if (i == 4)
		std::cout << "Inventory full !" << std::endl;
	else
		std::cout << "Materia " << m->getType() << " add at index " << i << " !" << std::endl;
		
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Index Error !" << std::endl;
	else if (inventory[idx] != NULL) {
		inventory[idx] = NULL;
		std::cout << "Materia n°" << idx << " dropped !" << std::endl;
	}
	else
		std::cout << "No Materia at this index !" << std::endl;
		
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Index Error !" << std::endl;
	else if (inventory[idx] != NULL)
		inventory[idx]->use(target);
	else
		std::cout << "No Materia at this index !" << std::endl;
}

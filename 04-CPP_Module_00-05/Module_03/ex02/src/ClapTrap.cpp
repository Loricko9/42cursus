/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:14:02 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 11:39:31 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name(""), Hit_pt(10), Energy_pt(10), Attack_damage(0)
{
	std::cout << "Default Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string str)
	:name(str), Hit_pt(10), Energy_pt(10), Attack_damage(0)
{
	std::cout << "Name Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
	:name(src.name), Hit_pt(src.Hit_pt), 
	Energy_pt(src.Energy_pt), Attack_damage(src.Attack_damage)
{
	std::cout << "Copy Constructor ClapTrap called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	name = rhs.name;
	Hit_pt = rhs.Hit_pt;
	Energy_pt = rhs.Energy_pt;
	Attack_damage = rhs.Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (Energy_pt > 0 && Hit_pt > 0)
	{
		std::cout << "ClapTrap " << name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << Attack_damage;
		std::cout << " points of damage!" << std::endl;
		Energy_pt--;
	}
	else if (Hit_pt > 0)
		std::cout << "ClapTrap " << name << " have no more Energy Point" << std::endl;
	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	Hit_pt -= amount;
	std::cout << "ClapTrap " << name;
	std::cout << " received " << amount;
	std::cout << " points of damage!" << std::endl;
	if (Hit_pt <= 0)
		std::cout << "ClapTrap " << name << " dead !" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_pt > 0 && Hit_pt > 0)
	{
		Hit_pt += amount;
		std::cout << "ClapTrap " << name;
		std::cout << " restored " << amount;
		std::cout << " points of damage!" << std::endl;
		Energy_pt--;
	}
	else if (Hit_pt > 0)
		std::cout << "ClapTrap " << name << " have no more Energy Point" << std::endl;
}

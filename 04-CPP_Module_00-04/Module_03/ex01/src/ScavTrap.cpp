/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:12:16 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/26 09:41:18 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:ClapTrap()
{
	Hit_pt = 100;
	Energy_pt = 50;
	Attack_damage = 20;
	std::cout << "Default Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string str)
	:ClapTrap(str)
{
	Hit_pt = 100;
	Energy_pt = 50;
	Attack_damage = 20;
	std::cout << "Name Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
	:ClapTrap(src.name)
{
	*this = src;
	std::cout << "Copy Constructor ScavTrap called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		Hit_pt = rhs.Hit_pt;
		Energy_pt = rhs.Energy_pt;
		Attack_damage = rhs.Attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << name;
	std::cout << " now in gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (Energy_pt > 0 && Hit_pt > 0)
	{
		std::cout << "Scavtrap " << name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << Attack_damage;
		std::cout << " points of damage!" << std::endl;
		Energy_pt--;
	}
	else if (Hit_pt > 0)
		std::cout << "Scavtrap " << name << " have no more Energy Point" << std::endl;
}

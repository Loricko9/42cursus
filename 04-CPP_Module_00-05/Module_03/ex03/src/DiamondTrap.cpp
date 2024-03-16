/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:49:47 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 12:27:44 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:ClapTrap(), FragTrap(), ScavTrap()
{
	DiamondTrap::name = "";
	ClapTrap::name = "_clap_name";
	FragTrap::Hit_pt = 100;
	ScavTrap::Energy_pt = 50;
	FragTrap::Attack_damage = 30;
	std::cout << "Default Constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string str)
	:ClapTrap(str), FragTrap(str), ScavTrap(str)
{
	DiamondTrap::name = str;
	ClapTrap::name = str + "_clap_name";
	FragTrap::Hit_pt = 100;
	ScavTrap::Energy_pt = 50;
	FragTrap::Attack_damage = 30;
	std::cout << "Name Constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
	:ClapTrap(src.name), FragTrap(src.name), ScavTrap(src.name)
{
	*this = src;
	std::cout << "Copy Constructor DiamondTrap called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &rhs)
{
	name = rhs.name;
	FragTrap::Hit_pt = rhs.FragTrap::Hit_pt;
	ScavTrap::Energy_pt = rhs.ScavTrap::Energy_pt;
	FragTrap::Attack_damage = rhs.FragTrap::Attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor DiamondTrap called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << DiamondTrap::name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}

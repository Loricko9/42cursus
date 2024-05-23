/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:31:14 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/26 09:42:41 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap()
{
	Hit_pt = 100;
	Energy_pt = 100;
	Attack_damage = 30;
	std::cout << "Default Constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string str)
	:ClapTrap(str)
{
	Hit_pt = 100;
	Energy_pt = 100;
	Attack_damage = 30;
	std::cout << "Name Constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
	:ClapTrap(src.name)
{
	*this = src;
	std::cout << "Copy Constructor FragTrap called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Hey there! How about we celebrate with a satisfying high five? You've been doing great, and I'm excited to share the positivity with a solid high five! 🙌";
	std::cout << std::endl;
}

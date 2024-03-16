/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:14:07 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 11:13:58 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string str);
	ClapTrap(const ClapTrap &src);
	ClapTrap&	operator=(const ClapTrap &rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
protected:
	std::string	name;
	int			Hit_pt;
	int			Energy_pt;
	int			Attack_damage;
};

#endif
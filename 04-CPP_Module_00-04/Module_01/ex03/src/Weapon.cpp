/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:18:30 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/22 16:24:26 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
	:type("")
{
	
}

Weapon::Weapon(std::string str)
	:type(str)
{
	
}

Weapon::~Weapon()
{
	
}

void	Weapon::setType(std::string str)
{
	type = str;
}

const std::string&	Weapon::getType() const
{
	return type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:18:01 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/13 15:57:27 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
public:
	HumanB(std::string str);
	~HumanB();
	void	attack() const;
	void	setWeapon(Weapon &wp);
private:
	Weapon		*weapon;
	std::string	name;
};

#endif
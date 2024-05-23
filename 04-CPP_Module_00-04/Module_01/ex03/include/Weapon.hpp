/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:17:23 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/22 16:24:33 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
public:
	Weapon(std::string str);
	Weapon();
	~Weapon();
	const std::string&	getType() const;
	void		setType(std::string str);
private:
	std::string	type;
};

#endif
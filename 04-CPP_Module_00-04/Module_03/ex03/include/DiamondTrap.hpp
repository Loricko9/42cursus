/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:48:58 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 12:24:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string str);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap&	operator=(const DiamondTrap &rhs);
	~DiamondTrap();
	void	whoAmI();
	using	ScavTrap::attack;
private:
	std::string	name;
};


#endif

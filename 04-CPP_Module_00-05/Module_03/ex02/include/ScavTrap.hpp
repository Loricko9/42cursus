/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:11:36 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 11:14:00 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string str);
	ScavTrap(const ScavTrap &src);
	ScavTrap&	operator=(const ScavTrap &rhs);
	~ScavTrap();
	void	guardGate();
	void	attack(const std::string& target);
private:
	
};

#endif

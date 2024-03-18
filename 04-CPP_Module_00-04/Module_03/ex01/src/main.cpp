/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:13:30 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 11:22:19 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	test1("Tabouret");

	for (int i = 0; i < 5; i++)
		test1.attack("Chaise");
	for (int i = 0; i < 5; i++)
		test1.beRepaired(1);
	test1.takeDamage(14);
	test1.attack("Chaise");
	
	ScavTrap	test2("L'autre");
	test2.attack("Chaise");
	test2.guardGate();
	test2.beRepaired(1);
	test2.takeDamage(200);
	test2.attack("Chaise");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:13:30 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 11:43:39 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	test1("Le Robot");

	for (int i = 0; i < 5; i++)
		test1.attack("Chaise");
	for (int i = 0; i < 5; i++)
		test1.beRepaired(1);
	test1.takeDamage(14);
	test1.attack("Chaise");
	
	std::cout << "--------------------------------------------" << std::endl;

	ScavTrap	test2("L'autre");
	test2.attack("Chaise");
	test2.guardGate();
	test2.beRepaired(1);
	test2.takeDamage(200);
	test2.attack("Chaise");

	std::cout << "--------------------------------------------" << std::endl;

	FragTrap	test3("L'alien");
	test3.attack("Chaise");
	test3.highFivesGuys();
	test3.beRepaired(8);
	test3.takeDamage(200);
	test3.attack("Chaise");
	
}

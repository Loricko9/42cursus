/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:53:55 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/13 12:56:06 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>

class	Zombie
{
public:
	Zombie();
	~Zombie();
	void	announce(void);
	void	Set_name(std::string str);
private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
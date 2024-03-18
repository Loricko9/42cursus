/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:31:31 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:52:26 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>

class	Animal
{
public:
	Animal();
	Animal(std::string str);
	Animal(const Animal &src);
	Animal&	operator=(const Animal &rhs);
	virtual ~Animal();
	virtual void	makeSound() const;
	std::string	getType() const;
protected:
	std::string	type;
};

#endif

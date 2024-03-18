/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:46 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 16:50:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string str);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal&	operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();
	void	makeSound() const;
	std::string		getType() const;
protected:
	std::string	type;
};

#endif
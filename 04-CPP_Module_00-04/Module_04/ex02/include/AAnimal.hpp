/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:31:31 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 12:06:03 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define	AANIMAL_HPP

#include <iostream>

class	AAnimal
{
public:
	AAnimal();
	AAnimal(std::string str);
	AAnimal(const AAnimal &src);
	AAnimal&	operator=(const AAnimal &rhs);
	virtual ~AAnimal();
	virtual void	makeSound() const = 0;
	virtual void 	addIdeas(std::string idea) = 0;
	virtual void 	think() = 0;
	std::string	getType() const;
protected:
	std::string	type;
};

#endif

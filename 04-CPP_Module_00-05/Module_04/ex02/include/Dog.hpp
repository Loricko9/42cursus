/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:30:27 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 12:10:44 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define	DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog &src);
	Dog&	operator=(const Dog &rhs);
	~Dog();
	void	makeSound() const;
	void	addIdeas(std::string idea);
	void	think();
private:
	Brain	*_Brain;
};

#endif

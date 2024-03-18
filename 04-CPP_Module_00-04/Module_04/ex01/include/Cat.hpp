/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:31:18 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 18:01:17 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &src);
	Cat&	operator=(const Cat &rhs);
	~Cat();
	void	makeSound() const;
	void	addIdeas(std::string idea);
	void	think();
private:
	Brain	*_Brain;
};


#endif

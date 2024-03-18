/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:16:53 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 19:11:43 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &src);
	Cure&	operator=(const Cure &rhs);
	~Cure();
	
	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif
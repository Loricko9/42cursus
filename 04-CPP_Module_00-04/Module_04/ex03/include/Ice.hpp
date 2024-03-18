/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:16:15 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 19:11:31 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class	Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &src);
	Ice&	operator=(const Ice &rhs);
	~Ice();
	
	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif

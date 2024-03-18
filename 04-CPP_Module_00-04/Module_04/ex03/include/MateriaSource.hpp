/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:35:41 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 21:04:56 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource&	operator=(const MateriaSource &rhs);
	~MateriaSource();
	
	void		learnMateria(AMateria *Materia);
	AMateria*	createMateria(std::string const & type);
private:
	AMateria	*mem[4];
};

#endif

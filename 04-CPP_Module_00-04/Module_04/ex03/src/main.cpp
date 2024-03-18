/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:12:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/17 21:41:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << "-------------------------------------------" << std::endl;

	Character* Cloud = new Character("Cloud");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Cloud->use(0, *bob); //err
	AMateria* Materia1 = src->createMateria("ice");
	Cloud->equip(Materia1);
	AMateria* Materia2 = src->createMateria("ice");
	Cloud->equip(Materia2);
	AMateria* Materia3 = src->createMateria("cure");
	Cloud->equip(Materia3);
	AMateria* Materia4 = src->createMateria("cure");
	Cloud->equip(Materia4);
	AMateria* Materia5 = src->createMateria("cure"); //err
	Cloud->equip(Materia5); //err (n'affiche rien)

	Cloud->use(3, *bob);
	Cloud->unequip(3);
	Cloud->unequip(3); //err
	Cloud->use(3, *bob); //err
	
	delete Materia4;
	delete Cloud;
	delete bob;
	delete me;
	delete src;
	return 0;
}

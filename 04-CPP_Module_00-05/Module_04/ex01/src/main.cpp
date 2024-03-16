/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:30:09 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 18:12:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	Dog		dog_test;
	Cat		cat_test;
	dog_test.addIdeas("eat a steack");
	cat_test.addIdeas("eat a fish");
	dog_test.think();
	cat_test.think();
	Dog		dog_res(dog_test);
	Cat		cat_res(cat_test);
	dog_res.think();
	cat_res.think();
	
	std::cout << "-----------------------------------------------------" << std::endl;
	
	Animal	*tab[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	tab[0]->addIdeas("eat a steack");
	tab[2]->addIdeas("eat a fish");
	tab[0]->think();
	tab[2]->think();
	
	for (int i = 0; i < 4; i++)
		delete tab[i];
	std::cout << "-----------------------------------------------------" << std::endl;
}

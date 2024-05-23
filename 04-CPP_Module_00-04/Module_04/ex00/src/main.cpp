/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:30:09 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/26 15:32:55 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!	
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	std::cout << "--------------------------------------------" << std::endl;
	const WrongAnimal* test1 = new WrongCat();
	const WrongCat* test2 = new WrongCat();
	std::cout << test1->getType() << " " << std::endl;
	std::cout << test2->getType() << " " << std::endl;
	test1->makeSound();
	test2->makeSound();
	delete test1;
	delete test2;
	
	return 0;
}

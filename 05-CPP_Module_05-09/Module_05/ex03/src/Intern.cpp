/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:22:26 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 10:11:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern&	Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	
}

AForm*	Intern::makeForm(const std::string &object, const std::string &target)
{
	std::string	cmp_form[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int	i = 0;
	while (i < 3 && cmp_form[i] != object)
		i++;
	switch (i)
	{
		case 0 : {
			AForm	*form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
		case 1 : {
			AForm	*form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
		case 2 : {
			AForm	*form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern : the form doesn't exist..." << std::endl;
	return (NULL);
}

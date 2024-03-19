/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:22 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 10:14:20 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	bob("bob", 5);
	Bureaucrat	Carol("Carol", 142);
	Intern		RandomIntern;
	
	std::cout << "---------ShrubberyForm----------" << std::endl;
	AForm	*form1;
	form1 = RandomIntern.makeForm("shrubbery creation", "form1");
	bob.executeForm(*form1);
	Carol.signForm(*form1);
	bob.executeForm(*form1);
	Carol.executeForm(*form1);
	delete form1;
	
	std::cout << "---------RobotomyForm-----------" << std::endl;
	AForm	*form2;
	form2 = RandomIntern.makeForm("robotomy request", "form1");
	bob.executeForm(*form2);
	Carol.signForm(*form2);
	bob.signForm(*form2);
	bob.executeForm(*form2);
	bob.executeForm(*form2);
	bob.executeForm(*form2);
	bob.executeForm(*form2);
	Carol.executeForm(*form2);
	delete form2;
	
	std::cout << "--------PresidentialForm--------" << std::endl;
	AForm	*form3;
	form3 = RandomIntern.makeForm("presidential pardon", "form1");
	bob.executeForm(*form3);
	Carol.signForm(*form3);
	bob.signForm(*form3);
	bob.executeForm(*form3);
	Carol.executeForm(*form3);
	delete form3;

	std::cout << "-----------ErrorForm------------" << std::endl;
	AForm	*Err;
	Err = RandomIntern.makeForm("Error", "form1");
	if (Err != NULL)
		Carol.signForm(*Err);
	else
		std::cout << "Errptr == NULL" << std ::endl;
}

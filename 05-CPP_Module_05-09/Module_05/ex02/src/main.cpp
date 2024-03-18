/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:22 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 18:44:46 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	bob("bob", 5);
	Bureaucrat	Carol("Carol", 142);
	
	std::cout << "---------ShrubberyForm----------" << std::endl;
	ShrubberyCreationForm	form1("form1");
	bob.executeForm(form1);
	Carol.signForm(form1);
	bob.executeForm(form1);
	Carol.executeForm(form1);
	
	std::cout << "---------RobotomyForm-----------" << std::endl;
	RobotomyRequestForm	form2("form2");
	bob.executeForm(form2);
	Carol.signForm(form2);
	bob.signForm(form2);
	bob.executeForm(form2);
	bob.executeForm(form2);
	bob.executeForm(form2);
	bob.executeForm(form2);
	Carol.executeForm(form2);
	
	std::cout << "--------PresidentialForm--------" << std::endl;
	PresidentialPardonForm	form3("form3");
	bob.executeForm(form3);
	Carol.signForm(form3);
	bob.signForm(form3);
	bob.executeForm(form3);
	Carol.executeForm(form3);
}

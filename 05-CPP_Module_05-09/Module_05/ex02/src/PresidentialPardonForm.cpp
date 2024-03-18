/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:20:48 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 17:50:06 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm(), target("")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &str)
	:AForm("PresidentialPardonForm", 25, 5), target(str)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	:AForm(src), target(src.target)
{
		
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void	PresidentialPardonForm::execute(const Bureaucrat &exec) const
{
	if (getSign() == false)
		throw AForm::NotSignedException();
	if (exec.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}

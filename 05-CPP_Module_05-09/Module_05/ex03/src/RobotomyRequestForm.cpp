/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:26 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 18:43:33 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm(), target("")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &str)
	:AForm("RobotomyRequestForm", 72, 45), target(str)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	:AForm(src), target(src.target)
{
		
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void	RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
	if (getSign() == false)
		throw AForm::NotSignedException();
	if (exec.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	static int i;
	if (i % 2 == 0)
		std::cout << target << " has been robotomized !" << std::endl;
	else
		std::cout << "The robotomy failed !" << std::endl;
	i++;
}

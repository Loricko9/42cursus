/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:12:27 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 18:33:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm(), target("")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &str)
	:AForm("ShrubberyCreationForm", 145, 137), target(str)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	:AForm(src), target(src.target)
{
		
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void	ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
	if (getSign() == false)
		throw AForm::NotSignedException();
	if (exec.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	
	std::string		f_name = target + "_shrubbery";
	std::ofstream	f_out(f_name.c_str());
	
	if (f_out.is_open())
	{
		f_out << "    *\n";
        f_out << "   ***\n";
        f_out << "  *****\n";
        f_out << " *******\n";
        f_out << "*********\n";
        f_out << "   |||\n";
        f_out << "   |||\n";
        f_out << "   |||\n";
        f_out.close();
	}
}

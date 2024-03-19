/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 16:14:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:name(""), sign(false), grade_req_sign(150), grade_req_exec(150)
{
	
}

AForm::AForm(const std::string &str, int i, int j)
	:name(str), sign(false), grade_req_sign(i), grade_req_exec(j)
{
	if (i > 150)
		throw AForm::GradeTooLowException();
	if (i <= 0)
		throw AForm::GradeTooHighException();
	if (j > 150)
		throw AForm::GradeTooLowException();
	if (j <= 0)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src)
	:name(src.name), sign(src.sign), grade_req_sign(src.grade_req_sign), grade_req_exec(src.grade_req_exec)
{
		
}

AForm&	AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		sign = rhs.sign;
	return (*this);
}

AForm::~AForm()
{
	
}

std::ostream&	operator<<(std::ostream &o, AForm &rhs)
{
	o << "Name of the AForm : " << rhs.getName() << std::endl;
	o << "Grade required for sign : " << rhs.getGradeSign() << std::endl;
	o << "Grade requiered for exec : " << rhs.getGradeExec() << std::endl;
	if (rhs.getSign())
		o << "Status : Sign";
	else
		o << "Status : Not sign";
	return (o);
}

const std::string&	AForm::getName() const
{
	return (name);
}

bool	AForm::getSign() const
{
	return (sign);
}

int	AForm::getGradeSign() const
{
	return (grade_req_sign);
}

int	AForm::getGradeExec() const
{
	return (grade_req_exec);
}

void	AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= grade_req_sign)
		sign = true;
	else
		throw AForm::GradeTooLowException();		
}

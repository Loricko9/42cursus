/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/27 15:19:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:name(""), sign(false), grade_req_sign(150), grade_req_exec(150)
{
	
}

Form::Form(const std::string &str, int i, int j)
	:name(str), sign(false), grade_req_sign(i), grade_req_exec(j)
{
	if (i > 150)
		throw Form::GradeTooLowException();
	if (i <= 0)
		throw Form::GradeTooHighException();
	if (j > 150)
		throw Form::GradeTooLowException();
	if (j <= 0)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &src)
	:name(src.name), sign(src.sign), grade_req_sign(src.grade_req_sign), grade_req_exec(src.grade_req_exec)
{
		
}

Form&	Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		sign = rhs.sign;
	return (*this);
}

Form::~Form()
{
	
}

std::ostream&	operator<<(std::ostream &o, Form &rhs)
{
	o << "Name of the Form : " << rhs.getName() << std::endl;
	o << "Grade required for sign : " << rhs.getGradeSign() << std::endl;
	o << "Grade requiered for exec : " << rhs.getGradeExec() << std::endl;
	if (rhs.getSign())
		o << "Status : Sign";
	else
		o << "Status : Not sign";
	return (o);
}

const std::string&	Form::getName()
{
	return (name);
}

bool	Form::getSign()
{
	return (sign);
}

int	Form::getGradeSign()
{
	return (grade_req_sign);
}

int	Form::getGradeExec()
{
	return (grade_req_exec);
}

void	Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= grade_req_sign)
		sign = true;
	else
		throw Form::GradeTooLowException();		
}

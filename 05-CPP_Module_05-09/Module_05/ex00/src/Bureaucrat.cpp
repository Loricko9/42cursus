/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:11 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 11:48:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name(""), grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string &str, int i)
	:name(str), grade(i)
{
	if (i > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		grade = 150;
	}
	if (i <= 0)
	{
		throw Bureaucrat::GradeTooHighException();
		grade = 1;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	:name(src.name), grade(src.grade)
{
		
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		grade = rhs.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	
}

const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

void	Bureaucrat::Decrement()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::Increment()
{
	if (grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

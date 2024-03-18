/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 15:28:46 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &str, int i);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat&	operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Grade too high !");
		}
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Grade too Low !");
		}
	};
	const std::string&	getName() const;
	int					getGrade() const;
	void				Increment();
	void				Decrement();
	void				signForm(Form &form);
private:
	const std::string	name;
	int					grade;
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat &rhs);

#endif

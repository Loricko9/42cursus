/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:52:05 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
public:
	Form();
	Form(const std::string &str, int i, int j);
	Form(const Form &src);
	Form&	operator=(const Form &rhs);
	~Form();

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Grade is too High !");
		}
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Grade is too Low !");
		}
	};

	const std::string&	getName();
	bool				getSign();
	int			getGradeSign();
	int			getGradeExec();
	void				beSigned(const Bureaucrat &src);
	
private:
	const std::string	name;
	bool				sign;
	const int			grade_req_sign;
	const int			grade_req_exec;
};

std::ostream&	operator<<(std::ostream &o, Form &rhs);

#endif

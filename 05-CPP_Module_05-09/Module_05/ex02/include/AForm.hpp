/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:52:05 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
#define	AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
public:
	AForm();
	AForm(const std::string &str, int i, int j);
	AForm(const AForm &src);
	AForm&	operator=(const AForm &rhs);
	virtual ~AForm();

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
	class	NotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Form not signed !");
		}
	};

	const std::string&	getName() const;
	bool				getSign() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	void				beSigned(const Bureaucrat &src);
	
	virtual void		execute(const Bureaucrat &exec) const = 0;
private:
	const std::string	name;
	bool				sign;
	const int			grade_req_sign;
	const int			grade_req_exec;
};

std::ostream&	operator<<(std::ostream &o, AForm &rhs);

#endif

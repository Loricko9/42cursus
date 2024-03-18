/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:20 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 17:23:34 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PresidentialPardonForm_HPP
#define	PresidentialPardonForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &str);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

	void	execute(const Bureaucrat &exec) const;
private:
	const std::string	target;
};

#endif

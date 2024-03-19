/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:06:47 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 17:29:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ShrubberyCreationForm_HPP
#define	ShrubberyCreationForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &str);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	void	execute(const Bureaucrat &exec) const;
private:
	const std::string	target;
};

#endif

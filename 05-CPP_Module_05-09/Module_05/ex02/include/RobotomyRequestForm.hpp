/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:16:38 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/18 17:31:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RobotomyRequestForm_HPP
#define	RobotomyRequestForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &str);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	void	execute(const Bureaucrat &exec) const;
private:
	const std::string	target;
};

#endif
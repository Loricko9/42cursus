/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:16:43 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 09:49:30 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class	Intern
{
public:
	Intern();
	Intern(const Intern &src);
	Intern&	operator=(const Intern &rhs);
	~Intern();

	AForm*	makeForm(const std::string &object, const std::string &target);
};

#endif

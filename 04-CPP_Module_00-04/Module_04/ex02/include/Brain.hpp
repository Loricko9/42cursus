/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:03:20 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/16 17:59:08 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
public:
	Brain();
	Brain(const Brain &src);
	Brain&	operator=(const Brain &rhs);
	~Brain();
	void	addSingleIdea(std::string &str, int i);
	void	getIdea();
private:
	std::string	ideas[100];
};

#endif


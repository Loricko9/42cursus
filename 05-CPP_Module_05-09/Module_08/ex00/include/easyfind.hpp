/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:40:36 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 13:31:39 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class	NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw() {
		return ("Val Not Found !");
	}
};

template<typename T>
void	easyfind(const T &container, int val)
{
	if (std::find(container.begin(), container.end(), val) == container.end())
		throw NotFoundException();
}

#endif

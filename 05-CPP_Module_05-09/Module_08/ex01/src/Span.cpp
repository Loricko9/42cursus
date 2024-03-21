/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:39:01 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 18:24:31 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int n)
	:N(n)
{
	
}

Span::Span(const Span &src)
	:N(src.N), lst(src.lst)
{
	
}

Span&	Span::operator=(const Span &rhs)
{
	if (this != &rhs) {
		N = rhs.N;
		lst = rhs.lst;
	}
		
	return (*this);
}

Span::~Span()
{
	
}

void	Span::addNumber(int nb)
{
	if (lst.size() + 1 > N)
		throw TooManyNbException();
	lst.push_back(nb);
}

void	Span::addNumber(std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
	if (lst.size() + std::distance(start, end) > N)
		throw TooManyNbException();
	lst.insert(lst.end(), start, end);
}

int	Span::longestSpan()
{
	if (lst.size() < 2)
		throw ListEmptyException();
	return (*std::max_element(lst.begin(), lst.end()) - *std::min_element(lst.begin(), lst.end()));
}

int	Span::shortestSpan()
{
	if (lst.size() < 2)
		throw ListEmptyException();
	int	min = __INT_MAX__;
	for (std::list<int>::const_iterator it1 = lst.begin(); it1 != lst.end(); ++it1)
	{
		for (std::list<int>::const_iterator it2 = it1; it2 != lst.end(); ++it2) {
			if (it1 == it2)
				continue;
			if (std::abs(*it1 - *it2) < min)
				min = std::abs(*it1 - *it2);
		}
	}
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:39:13 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 18:18:35 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <iterator>

class	Span
{
public:
	Span(unsigned int n);
	Span(const Span &src);
	Span&	operator=(const Span &rhs);
	~Span();

	class	TooManyNbException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Too Many Number in Span class !");
		}
	};
	class	ListEmptyException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("List empty or one element !");
		}
	};

	void	addNumber(int nb);
	void	addNumber(std::list<int>::const_iterator start, std::list<int>::const_iterator end);
	int		longestSpan();
	int		shortestSpan();
private:
	unsigned int N;
	std::list<int>	lst;
};

#endif

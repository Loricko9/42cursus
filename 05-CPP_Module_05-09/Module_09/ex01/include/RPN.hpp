/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:46:20 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/24 14:39:30 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class	RPN
{
public:
	RPN();
	RPN(const RPN &src);
	RPN&	operator=(const RPN &rhs);
	~RPN();

	class	BadInputException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Bad Input !");
			}
	};

	class	BadExpressionException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Bad expression !");
			}
	};

	void	addNb(const int nb);
	void	execCalc(const char c);
	int		getNb();
	int		getSize() const;
private:
	std::stack<int>	stack;
};

#endif

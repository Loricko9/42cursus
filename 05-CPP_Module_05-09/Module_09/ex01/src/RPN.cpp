/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:48:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/24 14:40:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}

RPN::RPN(const RPN &src)
	:stack(src.stack)
{

}

RPN&	RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		stack = rhs.stack;
	return (*this);
}

RPN::~RPN()
{
	
}

void	RPN::addNb(const int nb)
{
	stack.push(nb);
}

void	RPN::execCalc(const char c)
{
	int	second = getNb();
	int	first = getNb();

	switch (c)
	{
		case 42 : {
			stack.push(first * second);
			break;
		}
		case 43 : {
			stack.push(first + second);
			break;
		}
		case 45 : {
			stack.push(first - second);
			break;
		}
		case 47 : {
			stack.push(first / second);
			break;
		}
		default : {}
	}
}

int	RPN::getNb()
{
	if (!stack.empty()) {
		int temp = stack.top();
		stack.pop();
		return (temp);
	}
	throw BadExpressionException();
	return (0);
}

int	RPN::getSize() const
{
	return (stack.size());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:37:28 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/22 10:26:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>

template<typename T>
class	MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	~MutantStack() {};
	
	MutantStack(const MutantStack &src) : std::stack<T>(src) {};
	MutantStack&	operator=(const MutantStack &rhs) {
		std::stack<T>::operator=(rhs);
		return (*this);
	};
	
	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator	begin() {return(this->c.begin());};
	iterator	end() {return(this->c.end());};
};

#endif

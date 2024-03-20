/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:30:51 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/20 13:12:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp = b;
	b = a;
	a = temp;
}

template<typename T>
const T&	min(const T &a, const T &b)
{
	if (b <= a)
		return (b);
	return (a);
}

template<typename T>
const T&	max(const T &a, const T &b)
{
	if (b >= a)
		return (b);
	return (a);
}

#endif

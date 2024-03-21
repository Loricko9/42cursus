/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:16:56 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/21 10:22:05 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T>
void	iter(T *arr, size_t size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

template<typename T>
void	print(T &t)
{
	std::cout << t << " " << std::flush;
}

#endif

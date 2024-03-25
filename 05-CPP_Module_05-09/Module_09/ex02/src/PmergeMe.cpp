/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:55:28 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/25 19:11:00 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sys/time.h>

PmergeMe::PmergeMe(char **av)
	:duration_lst(0.0), duration_vector(0.0)
{
	for (int i = 0; av[i] != NULL; i++) {
		for (int j = 0; av[i][j] != '\0'; j++) {
			if (!isdigit(av[i][j]))
				throw BadArgException();
		}
		if (atol(av[i]) <= __INT_MAX__)
			vector.push_back(atol(av[i]));
		else
			throw IntOverflowException();
	}
	check_double_vect();
	for (int i = 0; av[i] != NULL; i++) {
		lst.push_back(atol(av[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
	:duration_lst(0.0), duration_vector(0.0),
	vector(src.vector), lst(src.lst)
{
	
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
		vector = rhs.vector;
		lst = rhs.lst;
		duration_lst = rhs.duration_lst;
		duration_vector = rhs.duration_vector;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	
}

std::ostream&	operator<<(std::ostream &o, const PmergeMe &rhs)
{
	for (std::vector<int>::const_iterator it1 = rhs.getBegin_vect(); it1 != rhs.getEnd_vect(); it1++) {
		o << *it1 << " " << std::flush;
	}
	/*for (std::list<int>::const_iterator it2 = rhs.getBegin_lst(); it2 != rhs.getEnd_lst(); it2++) {
		o << *it2 << " ";
	}*/
	return (o);
}

void	PmergeMe::check_double_vect() const
{
	for (std::vector<int>::const_iterator it1 = vector.begin(); it1 != vector.end(); it1++) {
		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != vector.end(); it2++) {
			if (*it2 == *it1)
				throw DoubleIntException();
		}
	}
}

void	PmergeMe::Sort_vect()
{
	struct	timeval start, end;
	gettimeofday(&start, NULL);	
	
	vector = Merge_vect(vector);
	
	gettimeofday(&end, NULL);
	long	sec = end.tv_sec - start.tv_sec;
	long	micro = end.tv_usec - start.tv_usec;
	duration_vector = (sec + micro) / 1000000.0;
}

std::vector<int>	PmergeMe::Merge_vect(std::vector<int> tab)
{
	if (tab.size() <= 1)
		return (tab);
	
	int	mid = tab.size() / 2;
	std::vector<int>	tab1;
	std::vector<int>	tab2;
	
	for (int i = 0; i < mid; i++)
		tab1.push_back(tab[i]);
	for (int i = mid; i < static_cast<int>(tab.size()); i++)
		tab2.push_back(tab[i]);
		
	return (Fusion_vect(Merge_vect(tab1), Merge_vect(tab2)));
}

std::vector<int>	PmergeMe::Fusion_vect(const std::vector<int> &tab1, const std::vector<int> &tab2) const
{
	std::vector<int>					res;
	std::vector<int>::const_iterator	it1 = tab1.begin();
	std::vector<int>::const_iterator	it2 = tab2.begin();
	while (it1 != tab1.end() && it2 != tab2.end())
	{
		if (*it1 < *it2) {
			res.push_back(*it1);
			it1++;
		}
		else {
			res.push_back(*it2);
			it2++;
		}
	}
	while (it1 != tab1.end()) {
		res.push_back(*it1);
		it1++;
	}
	while (it2 != tab2.end()) {
		res.push_back(*it2);
		it2++;
	}
	return (res);
}

void	PmergeMe::Sort_lst()
{
	struct	timeval start, end;
	gettimeofday(&start, NULL);	
	
	lst = Merge_lst(lst);
	
	gettimeofday(&end, NULL);
	long	sec = end.tv_sec - start.tv_sec;
	long	micro = end.tv_usec - start.tv_usec;
	duration_lst = (sec + micro) / 1000000.0;
}

std::list<int>	PmergeMe::Merge_lst(std::list<int> tab)
{
	if (tab.size() <= 1)
		return (tab);
	
	int	mid = tab.size() / 2;
	std::list<int>	tab1;
	std::list<int>	tab2;
	
	std::list<int>::const_iterator	it = tab.begin();
	for (int i = 0; i < mid; i++, it++)
		tab1.push_back(*it);
	for (int i = mid; i < static_cast<int>(tab.size()); i++, it++)
		tab2.push_back(*it);
		
	return (Fusion_lst(Merge_lst(tab1), Merge_lst(tab2)));
}

std::list<int>	PmergeMe::Fusion_lst(const std::list<int> &tab1, const std::list<int> &tab2) const
{
	std::list<int>					res;
	std::list<int>::const_iterator	it1 = tab1.begin();
	std::list<int>::const_iterator	it2 = tab2.begin();
	while (it1 != tab1.end() && it2 != tab2.end())
	{
		if (*it1 < *it2) {
			res.push_back(*it1);
			it1++;
		}
		else {
			res.push_back(*it2);
			it2++;
		}
	}
	while (it1 != tab1.end()) {
		res.push_back(*it1);
		it1++;
	}
	while (it2 != tab2.end()) {
		res.push_back(*it2);
		it2++;
	}
	return (res);
}

std::vector<int>::const_iterator	PmergeMe::getBegin_vect() const
{
	return (vector.begin());
}

std::vector<int>::const_iterator	PmergeMe::getEnd_vect() const
{
	return (vector.end());
}

std::list<int>::const_iterator	PmergeMe::getBegin_lst() const
{
	return (lst.begin());
}

std::list<int>::const_iterator	PmergeMe::getEnd_lst() const
{
	return (lst.end());
}

double	PmergeMe::getDuration(bool b) const
{
	if (b == true)
		return (duration_vector);
	return (duration_lst);
}

int	PmergeMe::getSize(bool b) const
{
	if (b == true)
		return (vector.size());
	return (lst.size());
}

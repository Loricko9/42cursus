/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:55:46 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/25 19:10:20 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <ostream>

class	PmergeMe
{
public:
	PmergeMe(char **av);
	PmergeMe(const PmergeMe &src);
	PmergeMe&	operator=(const PmergeMe &rhs);
	~PmergeMe();

	class	BadArgException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Bad argument !");
			}
	};

	class	DoubleIntException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Double detected !");
			}
	};

	class	IntOverflowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Numbre too high detected !");
			}
	};
	
	std::vector<int>::const_iterator	getBegin_vect() const;
	std::vector<int>::const_iterator	getEnd_vect() const;
	std::list<int>::const_iterator		getBegin_lst() const;
	std::list<int>::const_iterator		getEnd_lst() const;
	double								getDuration(bool b) const;
	int									getSize(bool b) const;

	void	check_double_vect() const;
	void	Sort_vect();
	void	Sort_lst();
private:
	double				duration_lst;
	double				duration_vector;
	std::vector<int>	vector;
	std::list<int>		lst;

	std::vector<int>	Merge_vect(std::vector<int> tab);
	std::vector<int>	Fusion_vect(const std::vector<int> &tab1, const std::vector<int> &tab2) const;
	std::list<int>	Merge_lst(std::list<int> tab);
	std::list<int>	Fusion_lst(const std::list<int> &tab1, const std::list<int> &tab2) const;
};

std::ostream&	operator<<(std::ostream &o, const PmergeMe &rhs);

#endif

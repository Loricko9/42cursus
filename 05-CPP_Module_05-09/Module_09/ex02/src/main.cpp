/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:52:57 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/25 19:12:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Error : Please add some number" << std::endl;
		return (1);
	}
	try {
		PmergeMe	Sort(av + 1);
		std::cout << "Before : " << Sort << std::endl;
		Sort.Sort_vect();
		Sort.Sort_lst();
		std::cout << "After : " << Sort << std::endl;
		std::cout << "Time to process a range of " << Sort.getSize(true) << " elements with std::vector :	" << Sort.getDuration(true) << " us" << std::endl;
		std::cout << "Time to process a range of " << Sort.getSize(false) << " elements with std::list :	" << Sort.getDuration(false) << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
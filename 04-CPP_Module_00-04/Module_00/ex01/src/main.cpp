/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:34:03 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/12 17:30:25 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	Book;
	while (1)
	{
		std::string str;
		std::cout << "PhoneBook> " << std::flush;
		std::cin >> str;
		if (str == "EXIT")
			break ;
		else if (str == "ADD")
			Book.AddContact();
		else if (str == "SEARCH")
			Book.SearchContact();
		else
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Exiting PhoneBook..." << std::endl;
}
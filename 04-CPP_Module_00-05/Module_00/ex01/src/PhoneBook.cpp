/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:14:41 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/12 19:33:20 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	
}

PhoneBook::~PhoneBook()
{
	
}

void	PhoneBook::AddContact()
{
	static int i = 0;
	if (i >= 8)
		i = 0;
	contact[i].Fill_Contact();
	contact[i].Change_index(1);
	for (int j = i - 1, index = 2; index <= 8; index++, j--)
	{
		if (j < 0)
			j = 7;
		if (contact[j].Get_index() > 0)
			contact[j].Change_index(index);
	}
	i++;
}

void	PhoneBook::SearchContact()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "-----------------PhoneBook-----------------" << std::endl;
	int	i = 0;
	while (i < 8 && contact[i].Get_index() != 1)
		i++;
	if (i > 7)
		std::cout << "                Book Empty !                " << std::endl;
	else
	{
		std::cout << "   Index  |  F. name |  L. Name | Nickname |" << std::endl;
		for (int index = 0; index < 8; index++, i--)
		{
			if (i < 0)
				i = 7;
			if (contact[i].Get_index() > 0)
				contact[i].Print_tab();
		}
		std::cout << std::endl;
	}
	std::cout << "Enter an index : " << std::flush;
	std::string	input;
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::istringstream	temp(input);
	int index;
	temp >> index;
	i = 0;
	while (i < 8 && contact[i].Get_index() != index)
		i++;
	if (i == 8)
		std::cout << "Error : can't find contact !" << std::endl;
	else
		contact[i].Print_data();
}
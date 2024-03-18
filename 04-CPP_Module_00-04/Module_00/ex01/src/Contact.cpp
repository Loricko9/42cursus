/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:15:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/12 19:25:02 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include "PhoneBook.hpp"

Contact::Contact()
	: index(-1)
{

}

Contact::~Contact()
{
	
}

int	Contact::Get_index() const
{
	return (index);
}

void	Contact::Change_index(int nb)
{
	index = nb;
}

void	Contact::Fill_Contact()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Fname = Get_input("Enter First Name : ");
	Lname = Get_input("Enter Last Name : ");
	Nickname = Get_input("Enter Nickname : ");
	Phone = Get_input("Enter Phone number : ");
	Secret = Get_input("Enter Darket Secret : ");
	index = 1;
}

std::string	Contact::Get_input(std::string str) const
{
	bool		trig = false;
	std::string	input;
	while (!trig)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			trig = true;
		else
		{
			std::cin.clear();
			std::cout << "Error, enter valid input !" << std::endl;
		}
	}
	return (input);
}

void	Contact::Print_tab() const
{
	std::stringstream ss;
	ss << index;
	std::cout << std::setw(10) << ss.str() << "|";
	if (Fname.length() > 10)
		std::cout  << std::setw(9) << Fname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << Fname << "|";
	if (Lname.length() > 10)
		std::cout << std::setw(9) << Lname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << Lname << "|";
	if (Nickname.length() > 10)
		std::cout << std::setw(9) << Nickname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << Nickname << "|";
	std::cout << std::endl;
}

void	Contact::Print_data() const
{
	std::cout << "First Name :  " << Fname << std::endl;
	std::cout << "Last Name :   " << Lname << std::endl;
	std::cout << "Nickname :    " << Nickname << std::endl;
	std::cout << "Phone nb :    " << Phone << std::endl;
	std::cout << "Secret :      " << Secret << std::endl;
}

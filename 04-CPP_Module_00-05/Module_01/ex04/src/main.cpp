/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:59 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/13 18:49:16 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
		std::cerr << "Error : Invalid number of parameters !" << std::endl;
	else
	{
		std::string		res;
		std::ifstream	f_in(av[1]);
		if (!f_in.is_open())
		{
			std::cerr << "Error : Cannot open the file !" << std::endl;
			return (1);
		}
		std::string		name_f_out = av[1];
		name_f_out += ".replace";
		std::ofstream	f_out(name_f_out.c_str());
		if (!f_out.is_open())
		{
			std::cerr << "Error : Cannot create the out file !" << std::endl;
			f_in.close();
			return (1);
		}
		while (std::getline(f_in, res))
		{
			size_t	occ = res.find(av[2]);
			while (occ != std::string::npos)
			{
				res.erase(occ, std::strlen(av[2]));
				res.insert(occ, av[3]);
				occ = res.find(av[2]);
			}
			f_out << res << std::endl;
		}
		f_in.close();
		f_out.close();
	}
}

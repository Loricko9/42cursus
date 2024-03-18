/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:53:29 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/13 13:14:56 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;
	
	std::cout << "Adress str : " << &str << std::endl;
	std::cout << "Adress strPTR : " << strPTR << std::endl;
	std::cout << "Adress strREF : " << &strREF << std::endl;

	std::cout << "Value str : " << str << std::endl;
	std::cout << "Value pointed strPTR : " << *strPTR << std::endl;
	std::cout << "Value pointed strREF : " << strREF << std::endl;
}

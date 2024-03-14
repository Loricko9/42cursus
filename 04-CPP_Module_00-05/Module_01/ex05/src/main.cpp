/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:53:11 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 10:37:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	Harl;
	std::string	str;

	std::cout << "Enter a level : " << std::flush;
	std::cin >> str;
	Harl.complain(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:30:28 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 15:52:51 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error : Enter only 1 argument !" << std::endl;
	else
	{
		std::string	arg(av[1]);
		ScalarConverter::convert(arg);
	}
}

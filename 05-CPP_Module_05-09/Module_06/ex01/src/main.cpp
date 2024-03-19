/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:41:16 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 18:08:15 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	Data	data(42);
	Data	*data_ptr = &data;
	std::cout << "Data address before serialize : " << data_ptr;
	std::cout << " | value i : " << data_ptr->getI() << std::endl;
	uintptr_t	PTR = Serializer::serialize(data_ptr);
	std::cout << "uintptr_t address after serialize : " << PTR << std::endl;
	Data	*new_ptr = Serializer::deserialize(PTR);
	std::cout << "Data address after deserialize : " << new_ptr;
	std::cout << " | value i : " << new_ptr->getI() << std::endl;
}
	

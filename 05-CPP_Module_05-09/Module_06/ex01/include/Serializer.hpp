/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:41:55 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 17:53:48 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class	Serializer
{
public:
	Serializer();
	Serializer(const Serializer &src);
	Serializer&	operator=(const Serializer &rhs);
	~Serializer();

	static uintptr_t		serialize(Data* ptr);
	static Data*			deserialize(uintptr_t raw);
	virtual void	instance() = 0;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:56 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/19 18:05:58 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Data_HPP
#define Data_HPP

class	Data
{
public:
	Data();
	Data(int nb);
	Data(const Data &src);
	Data&	operator=(const Data &rhs);
	~Data();

	int	getI();
private:
	int i;
};

#endif
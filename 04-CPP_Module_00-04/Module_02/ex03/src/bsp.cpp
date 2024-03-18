/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:05:41 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/15 10:03:22 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	denom = ((b.Get_y() - c.Get_y()) * (a.Get_x() - c.Get_x()) + (c.Get_x() - b.Get_x()) * (a.Get_y() - c.Get_y()));
	Fixed	Barycentre1 = ((b.Get_y() - c.Get_y()) * (point.Get_x() - c.Get_x()) + (c.Get_x() - b.Get_x()) * (point.Get_y() - c.Get_y())) / denom;
	Fixed	Barycentre2 = ((c.Get_y() - a.Get_y()) * (point.Get_x() - c.Get_x()) + (a.Get_x() - c.Get_x()) * (point.Get_y() - c.Get_y())) / denom;
	Fixed	Barycentre3(1);
	Barycentre3 = Barycentre3 - Barycentre1 - Barycentre2;
	
	if ((Barycentre1 > 0 && Barycentre1 < 1) && (Barycentre2 > 0 && Barycentre2 < 1) && (Barycentre3 > 0 && Barycentre3 < 1))
		return (true);
	return (false);
}
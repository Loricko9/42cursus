/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:05:45 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/15 09:40:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	:x(0), y(0)
{
	
}

Point::Point(const Point& src)
	:x(src.x), y(src.y)
{
	
}

Point::Point(const float x_src, const float y_src)
	:x(x_src), y(y_src)
{
	
}

Point&	Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		(Fixed)x = rhs.x;
		(Fixed)y = rhs.y;
	}
	return (*this);
}

Fixed	Point::Get_x() const
{
	return ((Fixed)x);
}

Fixed	Point::Get_y() const
{
	return ((Fixed)y);
}

Point::~Point()
{
	
}

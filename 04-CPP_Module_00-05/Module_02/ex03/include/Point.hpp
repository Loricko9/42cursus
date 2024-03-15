/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:05:17 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/15 09:40:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
public:
	Point();
	Point(const Point& src);
	Point(const float x_src, const float y_src);
	Point&	operator=(const Point& rhs);
	~Point();
	Fixed	Get_x() const;
	Fixed	Get_y() const;
private:
	const Fixed x;
	const Fixed	y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
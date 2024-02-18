/****************************************************************************************
* ALI SAHBAZ
*
*
* MY DESIGN PATTERNS WORKSHOP
*
* Date          : 17.02.2024
* By            : Ali Þahbaz
* e-mail        : ali_sahbaz@outlook.com
*/
#ifndef __POINT_H
#define __POINT_H

#include <iostream>
#include <utility>

template<typename Type = double>
struct point
{
	point() : x(0), y( 0 ) {}

	point(Type _x , Type _y) : x(_x), y(_y) {}

	~point() = default;
	  
	std::pair<Type, Type> operator()() const {
		return std::make_pair(x, y);
	}

	friend std::ostream& operator<<(std::ostream& os, const point& me) {
		os << "x: " << me.x << ", y: " << me.y;
		return os;
	}
	 
	Type x;

	Type y;
};

/** 
 
---- ex:  ---------------

	point my_obj{ 5 , 8 };

	auto [x, y] = my_obj();

	std::cout << my_obj;

-------------------------
*/
 
#endif  

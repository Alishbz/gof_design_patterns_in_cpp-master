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
#ifndef __SQUARE_H
#define __SQUARE_H


#include "point.h" 

class square  
{
public:

    explicit square(double width, double height)
        : m_width(width), m_height(height), m_point(point<double>(0, 0))
    {

    }

    explicit square(double width, double height, point<double>  _point)
        : m_width(width), m_height(height), m_point(point(_point.x, _point.y))
    {

    }
     
    std::pair<double, double> operator()() const {
        return std::make_pair(m_width, m_height);
    }
       
    const point<double>& center() const { return m_point; }
     
private:

    double m_width;
    double m_height;

    point<double> m_point;
};

 

#endif  

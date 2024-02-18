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
#ifndef __CIRCLE_H
#define __CIRCLE_H


#include "point.h"
#include "shape.h" 

 class circle : public shape
{
public: 

    explicit circle(double radius)
        : m_radius(radius), m_point(point<double>(0, 0))
    {

    }
      
    explicit circle(double radius, point<double>  _point)
        : m_radius(radius), m_point(point(_point.x, _point.y))
    {

    }

    double radius() const { return m_radius; }  

    const point<double>& center() const { return m_point; }

    /*** interface ***/

    void draw() const override;


private:

    double m_radius;  

    point<double> m_point;
};

#endif  
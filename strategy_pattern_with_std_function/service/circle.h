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
#include <functional>

 class circle : public shape
{
public: 

    using draw_circle_strategy = std::function<void(circle const&  )>;

    explicit circle(double radius)
        : m_radius(radius), m_point(point<double>(0, 0)) , m_drawer(nullptr)
    {

    }
      
    explicit circle(double radius, point<double>  _point)
        : m_radius(radius), m_point(point(_point.x, _point.y)), m_drawer(nullptr)
    {

    }

    explicit circle(double radius, point<double>  _point, draw_circle_strategy drawer)
        : m_radius(radius), m_point(point(_point.x, _point.y)), m_drawer(std::move(drawer))
    {

    }

    double radius() const { return m_radius; }  

    const point<double>& center() const { return m_point; }

    /*** interface ***/
      
    void draw( ) const override
    {
        if(m_drawer)
            m_drawer(*this );
    }
private:

    double m_radius;  

    point<double> m_point;

    draw_circle_strategy m_drawer;
};

#endif  
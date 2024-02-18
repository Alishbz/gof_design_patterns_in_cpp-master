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
#include "shape_visitor.h" 

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
      
#ifdef ACYCLIC_DESIGN_MODE

    void accept(visitor_base const& v) override {
        if (auto const* cv = dynamic_cast<shape_visitor<circle> const*>(&v)) {
            cv->visit(*this);
        }
    }


#else

    void accept(shape_visitor const& v) override { v.visit(*this); }

#endif 
  

private:

    double m_radius;  

    point<double> m_point;
};

#endif  
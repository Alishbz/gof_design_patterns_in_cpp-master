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
#include "shape.h"   
#include "strategy.h" 

class square : public shape
{
public:
    using draw_square_strategy = draw_strategy<square>;

    explicit square(double width, double height)
        : m_width(width), m_height(height), m_point(point<double>(0, 0)), m_drawer(nullptr)
    {

    }

    explicit square(double width, double height, point<double>  _point)
        : m_width(width), m_height(height), m_point(point(_point.x, _point.y)), m_drawer(nullptr)
    {

    }

    explicit square(double width, double height, point<double>  _point, std::unique_ptr<draw_square_strategy> drawer)
        : m_width(width), m_height(height), m_point(point(_point.x, _point.y)), m_drawer(std::move(drawer))
    {

    }

    std::pair<double, double> operator()() const {
        return std::make_pair(m_width, m_height);
    }
       
    const point<double>& center() const { return m_point; }

    /*** interface ***/

    void draw() const override
    {
        if (m_drawer)
            m_drawer->draw(*this);
    }

private:

    double m_width;
    double m_height;

    point<double> m_point;

    std::unique_ptr<draw_square_strategy> m_drawer;
};

 

#endif  

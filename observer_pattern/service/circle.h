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
#include "observer.h" 
#include <set>

 class circle : public shape
{
public: 

    enum draw_state
    {
        draw_circle_mode_1,
        draw_circle_mode_2
    };

    using circle_observer = observer<circle, draw_state>;

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

    /***/

    void notify(draw_state property) {
        for (auto iter = begin(observers_); iter != end(observers_); )
        {
            auto const pos = iter++;
            (*pos)->update(*this, property);
        }
    }

    bool attach(circle_observer* observer) {
         
        auto [pos, success] = observers_.insert(observer);
        return success;
    }

    bool detach(circle_observer* observer) {
        return (observers_.erase(observer) > 0U);
    }

    /*** interface ***/
      
    void draw() const override;

private:

    double m_radius;  

    point<double> m_point;

    std::set<circle_observer*> observers_;
}; 

#endif  
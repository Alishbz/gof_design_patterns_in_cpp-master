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
#include "observer.h" 
#include <set>

class square : public shape
{
public:
    enum draw_state
    {
        draw_square_mode_1,
        draw_square_mode_2
    };

    using square_observer = observer<square, draw_state>;

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

    /***/

    void notify(draw_state property) {
        for (auto iter = begin(observers_); iter != end(observers_); )
        {
            auto const pos = iter++;
            (*pos)->update(*this, property);
        }
    }

    bool attach(square_observer* observer) {

        auto [pos, success] = observers_.insert(observer);
        return success;
    }

    bool detach(square_observer* observer) {
        return (observers_.erase(observer) > 0U);
    }

    /*** interface ***/

    void draw() const override;

private:

    double m_width;
    double m_height;

    point<double> m_point;
     
    std::set<square_observer*> observers_; 
};

 

#endif  

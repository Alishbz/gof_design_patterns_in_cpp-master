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
#ifndef __OPENGL_MASTER_H
#define __OPENGL_MASTER_H

#include "circle.h" 
#include "square.h"  


class OpenGL_circle : public circle
{
public: 
    explicit OpenGL_circle(double radius)
        : circle(radius)
    {

    }

    explicit OpenGL_circle(double radius, point<double>  _point)
        : circle(radius , _point)
    {


    }

    //void draw() const override;  
     void draw() const final;
};
 



class OpenGL_square : public square
{
public:
    
    explicit OpenGL_square(double width, double height)
        : square(width, height)
    {

    }

    explicit OpenGL_square(double width, double height, point<double>  _point)
        : square(width, height, _point)
    {

    }

    //void draw() const override;  
    void draw() const final;
};

  

#endif  

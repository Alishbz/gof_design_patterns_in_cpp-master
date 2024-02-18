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


class OpenGL_circle : public draw_strategy<circle>
{
public: 

    explicit OpenGL_circle( ) {}
    
    void draw(circle const& cr) const override;
};
 



class OpenGL_square : public draw_strategy<square>
{
public:
    
    explicit OpenGL_square( )  {}
     
    void draw(square const& sq ) const override;
};

  

#endif  

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


class OpenGL_circle  
{
public: 

    explicit OpenGL_circle( ) {}
    
    void operator()(circle const& cr) const;
};
 



class OpenGL_square  
{
public:
    
    explicit OpenGL_square( )  {}

    void operator()(square const& sq) const; 
};

  

#endif  

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
#ifndef __DRAWER_H
#define __DRAWER_H

 
#include "shape_visitor.h" 
 
class circle;
class square;
 
#ifdef ACYCLIC_DESIGN_MODE 

class drawer : public visitor_base 
             , public shape_visitor<circle>
             , public shape_visitor<square>

#else

 class drawer : public shape_visitor

#endif  
{
public:
    void visit(circle const& c /*, ...*/) const override;

    void visit(square const& s /*, ...*/) const override;
};

#endif  

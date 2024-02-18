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
#ifndef __SHAPE_H
#define __SHAPE_H
 
#include "shape_visitor.h" 

/** common interface and reach adress support for abstract logic designer **/
class shape
{
public:

	shape() = default;

	virtual ~shape() = default;
	  
#ifdef ACYCLIC_DESIGN_MODE

	virtual void accept(visitor_base const& v) = 0;

#else

	virtual void accept(shape_visitor const& v) = 0; 

#endif 

};
 

 


#endif  
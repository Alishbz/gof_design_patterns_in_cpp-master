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

#ifndef __SHAPE_VISITOR_H
#define __SHAPE_VISITOR_H

//#define ACYCLIC_DESIGN_MODE    1

class circle;
class square;
 
#ifdef ACYCLIC_DESIGN_MODE

	template< typename T >
	class shape_visitor
	{
	protected:
		virtual ~shape_visitor() = default;

	public:
		virtual void visit(T const&) const = 0;
	};

	class visitor_base
	{
	public:
		virtual ~visitor_base() = default;
	};

#else
	class shape_visitor
	{
	public:
		virtual ~shape_visitor() = default;

		virtual void visit(circle const&) const = 0;
		virtual void visit(square const&) const = 0;
	}; 
#endif 

#endif  
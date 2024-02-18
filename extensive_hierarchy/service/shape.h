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
  

/** common interface and reach adress support for abstract logic designer **/
class shape
{
public:

	shape() = default;

	virtual ~shape() = default;
	  
	virtual void draw( ) const = 0;

};
  


#endif  
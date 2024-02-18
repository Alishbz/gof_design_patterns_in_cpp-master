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

  
 
class circle;
class square;

class drawer   
{
public: 
    void operator()(circle const& c ) const  ;

    void operator()(square const& s  ) const  ;
};

#endif  

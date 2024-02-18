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
#ifndef __STRATEGY_H
#define __STRATEGY_H

template< typename T >
class draw_strategy
{
public:
	virtual ~draw_strategy() = default;
	virtual void draw(T const&) const = 0;
};
 

#endif  

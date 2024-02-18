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
#ifndef __OBSERVER_H
#define __OBSERVER_H

#define MODERN_OBSERVER  1   /** or comment **/

#ifdef MODERN_OBSERVER

#include <functional>

template< typename Subject, typename StateTag >
class observer
{
public:
    using OnUpdate = std::function<void(Subject const&, StateTag)>;
     
    explicit observer(OnUpdate onUpdate)
        : onUpdate_{ std::move(onUpdate) }
    { 
    }
     
    void update(Subject const& subject, StateTag property)
    {
        onUpdate_(subject, property);
    }

private:
    OnUpdate onUpdate_;
};

#else
template< typename Subject, typename StateTag >
class observer
{
public:
	virtual ~observer() = default;

	virtual void update(Subject const& subject, StateTag property) = 0;
};
 
#endif  


#endif  

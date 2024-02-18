/****************************************************************************************
* ALI SAHBAZ  -  ASOS
*
* 
* MY DESIGN PATTERNS WORKSHOP 
*
* Date          : 17.02.2024
* By            : Ali Şahbaz
* e-mail        : ali_sahbaz@outlook.com 
*/  
#include <iostream>
#include <memory>
#include <vector>

#include "circle.h" 
#include "square.h" 
#include "observer.h" 
 

static void draw_all_shapes(std::vector<std::unique_ptr<shape>> const& shapes)
{
    for (auto const& shape : shapes)
    {
        shape->draw();
    }
}

    

#ifdef MODERN_OBSERVER
 
#include <cstdlib>

static void circle_state_changed(circle const& person, circle::draw_state st)
{
    std::cout << "\n circle mode changed : " << st << "\n" << std::endl;
}
 
#else
 

class user_circle_observer : public observer<circle, circle::draw_state>
{
public:
    void update(circle const& cr, circle::draw_state st) override {
        std::cout << "\n circle mode changed : " << st << "\n" << std::endl;
    }
};


class user_square_observer : public observer<square, square::draw_state>
{
public:
    void update(square const& cr, square::draw_state st) override {
        std::cout << "\n square mode changed : " << st << "\n" << std::endl;
    }
};

#endif  




int main() { 
      
    using shapes_t = std::vector<std::unique_ptr<shape>>;
 
    std::cout << "ASOS test 8 , Design pattern snacks starting \n" << std::endl;
 
    shapes_t shapes{}; 
       
    /*** observer pattern side *****/

#ifdef MODERN_OBSERVER

    using circle_obs   = observer<circle, circle::draw_state>;
    using square_obs   = observer<square, square::draw_state>;

    square_obs square_state_changed(
        [ ](square const& cr, square::draw_state st) {
           
                std::cout << "\n square mode changed : " << st << "\n" << std::endl;
           
    });

    circle_obs c_obs(circle_state_changed);
    square_obs s_obs(square_state_changed);

#else

    user_circle_observer  c_obs;
    user_square_observer  s_obs;
     
#endif 

    square my_sq{ 4, 4, point<double>{ 10, 20 } };
    circle my_cr{ 4, point<double>{ 6, 25 } };

    my_sq.attach(&s_obs); 
    my_cr.attach(&c_obs);

    my_sq.notify(square::draw_state::draw_square_mode_2);
    my_cr.notify(circle::draw_state::draw_circle_mode_1);




     


    /*** normal drawing  *****/

    
    shapes.emplace_back(std::make_unique<circle>(8, point<double>{ 18, 25 } ));
    shapes.emplace_back(std::make_unique<square>(10, 10, point<double>{ 22, 16 } ));
    shapes.emplace_back(std::make_unique<circle>(6, point<double>{ 15, 20 } ));
         
    draw_all_shapes(shapes);
     


    for (int i = 0; i < 20; i++) { std::cout <<  "\n"; }


    /**************/
       
    return 0;
}





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
#include "main.h"
#include <iostream>
#include <memory>
#include <vector>

#include "drawer.h" 
#include "square.h" 
#include "circle.h"

 

static void draw_all_shapes(std::vector<std::unique_ptr<shape>> const& shapes)
{
    for (auto const& shape : shapes)
    {
        shape->accept(drawer{});
    }
}



int main() { 
      
    using shapes_t = std::vector<std::unique_ptr<shape>>;

#ifdef ACYCLIC_DESIGN_MODE 
    std::cout << "ASOS acyclic design pattern active, test2 , Design pattern snacks starting \n" << std::endl; 
#else
    std::cout << "ASOS cyclic design pattern active, test2 , Design pattern snacks starting \n" << std::endl;
#endif 
   

    point<double> test_point{ 10 , 10 };
       
    /********/

    shapes_t shapes{};

    shapes.emplace_back(std::make_unique<circle>(4, test_point) );
    shapes.emplace_back(std::make_unique<square>(4 , 4, point<double>{ 5 , 8 })); 
    shapes.emplace_back(std::make_unique<circle>(8, point<double>{ 15, 12 }));
    shapes.emplace_back(std::make_unique<square>(10, 10, point<double>{ 20, 15 }));
    shapes.emplace_back(std::make_unique<circle>(6, point<double>{ 25, 20 }));
         
    draw_all_shapes(shapes);
     
    for (int i = 0; i < 20; i++) { std::cout <<  "\n"; }


    /**************/
      
    auto [x, y] = test_point(); // opsional

    std::cout << " \n point " << test_point << " \n  \n";

    return 0;
}





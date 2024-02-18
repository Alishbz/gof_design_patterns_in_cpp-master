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

#include "shape.h" 
#include "point.h" 
#include "openGL_master.h" 
 

static void draw_all_shapes(std::vector<std::unique_ptr<shape>> const& shapes)
{
    for (auto const& shape : shapes)
    {
        shape->draw();
    }
}




int main() { 
      
    using shapes_t = std::vector<std::unique_ptr<shape>>;
 
    std::cout << "ASOS test4 , Design pattern snacks starting \n" << std::endl;
 
    shapes_t shapes{};
     
    point<double> test_point{ 10 , 10 };
       
    /********/
     
    shapes.emplace_back(std::make_unique<OpenGL_circle>(4, test_point) );
    shapes.emplace_back(std::make_unique<OpenGL_square>(4 , 4, point<double>{ 5 , 14 }));
    shapes.emplace_back(std::make_unique<OpenGL_circle>(8, point<double>{ 15, 8 }));
    shapes.emplace_back(std::make_unique<OpenGL_square>(10, 10, point<double>{ 16, 15 }));
    shapes.emplace_back(std::make_unique<OpenGL_circle>(6, point<double>{ 25, 18 }));
         
    draw_all_shapes(shapes);
     
    for (int i = 0; i < 20; i++) { std::cout <<  "\n"; }


    /**************/
      
    auto [x, y] = test_point(); // opsional

    std::cout << " \n point " << test_point << " \n  \n";

    return 0;
}





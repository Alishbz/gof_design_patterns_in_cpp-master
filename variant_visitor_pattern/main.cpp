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
#include <variant>

#include "drawer.h" 
#include "square.h" 
#include "circle.h"

using shape = std::variant<circle, square>;
using shapes_t = std::vector<shape>;


static void draw_all_shapes(shapes_t const& _shapes)
{
    for (auto const& _shape : _shapes)
    {
        std::visit(drawer{}, _shape); // drawer could be lambda 
    }
}



int main() { 
       
    std::cout << "ASOS , test3 , Design pattern snacks starting \n" << std::endl;

    point<double> test_point{ 10 , 10 };
       
    /********/

    shapes_t shapes{};

    shapes.emplace_back(circle{ 4, test_point });
    shapes.emplace_back(square{ 4 , 4, point<double>{ 5 , 8 } });
    shapes.emplace_back(circle{ 8, point<double>{ 15, 12 } });
    shapes.emplace_back(square{ 10, 10, point<double>{ 20, 15 } });
    shapes.emplace_back(circle{ 6, point<double>{ 25, 20 }});
         
    draw_all_shapes(shapes);
     
    for (int i = 0; i < 20; i++) { std::cout <<  "\n"; }


    /**************/
      
    auto [x, y] = test_point(); // opsional

    std::cout << " \n point " << test_point << " \n  \n";

    return 0;
}





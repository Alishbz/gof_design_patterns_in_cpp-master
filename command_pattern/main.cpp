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

#include "square.h" 
#include "circle.h"
#include "command.h"



int main() { 
       
    std::cout << "ASOS , test6 , Design pattern snacks starting \n" << std::endl;
     
    /********/

    shapes_manager  command_prosseor;

    auto sq1 = std::make_unique <square>( 4 , 4, point<double>{ 5 , 8 } );
    auto sq2 = std::make_unique <square>(4, 2, point<double>{ 11, 12 });
    auto cr1 = std::make_unique <circle>(6,  point<double>{ 15, 15 });
    auto cr2 = std::make_unique <circle>(3,  point<double>{ 10, 7 });

    command_prosseor.compute(std::move(sq1));
    command_prosseor.compute(std::move(sq2));
    command_prosseor.compute(std::move(cr1));
    command_prosseor.compute(std::move(cr2));
     
    for (int i = 0; i < 20; i++) { std::cout <<  "\n"; }


    /**************/
       

    return 0;
}





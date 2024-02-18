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

#include "openGL_master.h" 
#include "square.h" 
 
#ifdef _WIN32
#include <windows.h>

namespace {
    BOOL setxy(int x, int y)
    {
        COORD c = { x,y };
        return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
}

#elif __linux__
#warning "you must add linux lib"
#elif __APPLE__
#warning "you must add mac lib"
#else
#warning "OS is not known"
#endif



void OpenGL_square::draw(square const& sq) const 
{
  
    point<double> p = sq.center(); 
    int x = static_cast<int>(p.x);
    int y = static_cast<int>(p.y);

    auto [m_width, m_height] = sq();

    using namespace std;
    setxy(x, y);  cout << char(201);
    for (int i = 1; i < m_width; i++)cout << char(205);
    cout << char(187);
    setxy(x, m_height + y); cout << char(200);
    for (int i = 1; i < m_width; i++)cout << char(205);
    cout << char(188);
    for (int i = y + 1; i < m_height +  y; i++)
    {
        setxy(x, i); cout << char(186);
        setxy(x + m_width, i); cout << char(186);
    }
    setxy(0, 0);

} 
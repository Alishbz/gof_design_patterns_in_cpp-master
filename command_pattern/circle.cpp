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

#include "circle.h" 
   
#ifdef _WIN32
#include <windows.h>

namespace {
    BOOL setxy(int x, int y)
    {
        COORD c = { x,y };
        return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    void setcolor(WORD color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        return;
    }

    void drawpixel(unsigned char x, unsigned char y, unsigned char Color) {
        setcolor(Color);
        setxy(x, y);   std::cout << "*";
    }
}

#elif __linux__
#warning "you must add linux lib"
#elif __APPLE__
#warning "you must add mac lib"
#else
#warning "OS is not known"
#endif

  

//
//     colors:
//     0 = Black
//     1 = Blue
//     2 = Green
//     3 = Cyan
//     4 = Red
//     5 = Magenta
//     6 = Yellow
//     7 = LightGray
//     8 = DarkGray
//     9 = LightBlue
//     10 = LightGreen
//     11 = LightCyan
//     12 = LightRed
//     13 = LightMagenta
//     14 = LightYellow
//     15 = White

void circle::draw()const {
    
    int x = static_cast<int>(m_point.x);
    int y = static_cast<int>(m_point.y);
    int a = static_cast<int>(m_radius);
    int b = static_cast<int>(m_radius);
    int color = 6;

    int wx, wy;
    int thresh;
    int asq = a * a;
    int bsq = b * b;
    int xa, ya;

    drawpixel(x, y + b, color);
    drawpixel(x, y - b, color);

    wx = 0;
    wy = b;
    xa = 0;
    ya = asq * 2 * b;
    thresh = asq / 4 - asq * b;

    for (;;) {
        thresh += xa + bsq;

        if (thresh >= 0) {
            ya -= asq * 2;
            thresh -= ya;
            wy--;
        }

        xa += bsq * 2;
        wx++;

        if (xa >= ya)
            break;


        drawpixel(x + wx, y - wy, color);
        drawpixel(x - wx, y - wy, color);
        drawpixel(x + wx, y + wy, color);
        drawpixel(x - wx, y + wy, color);
    }

    drawpixel(x + a, y, color);
    drawpixel(x - a, y, color);

    wx = a;
    wy = 0;
    xa = bsq * 2 * a;

    ya = 0;
    thresh = bsq / 4 - bsq * a;

    for (;;) {
        thresh += ya + asq;

        if (thresh >= 0) {
            xa -= bsq * 2;
            thresh = thresh - xa;
            wx--;
        }

        ya += asq * 2;
        wy++;

        if (ya > xa)
            break;

        drawpixel(x + wx, y - wy, color);
        drawpixel(x - wx, y - wy, color);
        drawpixel(x + wx, y + wy, color);
        drawpixel(x - wx, y + wy, color);
    }
} 
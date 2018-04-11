#ifndef DRAWING_H_INCLUDED
#define DRAWING_H_INCLUDED

#include <windows.h>
#include "figure.h"
#include "circle.h"
#include "ellipse.h"
#include "square.h"
#include "rectangle.h"
#include "template_functions.h"


void drawSquare(HDC hdc, figure* square)
{
    Rectangle(hdc, square->get_startX(), square->get_startY(), square->get_endX(), square->get_endY());
    return;
}

void drawRectangle(HDC hdc, figure* rectangle)
{
    Rectangle(hdc, rectangle->get_startX(), rectangle->get_startY(), rectangle->get_endX(), rectangle->get_endY());
    return;
}

void drawEllipse(HDC hdc, figure* ellipse)
{
    Ellipse(hdc, ellipse->get_startX(), ellipse->get_startY(), ellipse->get_endX(), ellipse->get_endY());
    return;
}

void drawCircle(HDC hdc, figure* circle)
{
    Ellipse(hdc, circle->get_startX(), circle->get_startY(), circle->get_endX(), circle->get_endY());
    return;
}
#endif // DRAWING_H_INCLUDED

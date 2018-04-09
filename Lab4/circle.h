#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <cmath>
#define pi 3.14
#include "figure.h"
#include "template_functions.h"

class circle: public figure
{
    private:
        const std::string name = "circle";          // имя фигуры
                                                    //
        int startX;                                 // позиция левого верхнего угла в проекции на ось Ox.
                                                    //
        int startY;                                 // позиция левого верхнего угла в проекции на ось Oy.
                                                    //
        int endX;                                   // позиция правого нижнего угла в проекции на ось Ox.
                                                    //
        int endY;                                   // позиция правого нижнего угла в проекции на ось Oy
                                                    //
        int centerX;                                // координата центра круга в проекции на ось Ox.
                                                    //
        int centerY;                                // координата центра круга в проекции на ось Oy.
                                                    //
        int speed;                                  // скорость движения круга
                                                    //
        int angle;                                  // угол движения круга
                                                    //
        int radius;                                 // радиус круга
                                                    //
        int RGB_RED;                                // красный цвет [0..255]
                                                    //
        int RGB_GREEN;                              // зелёный цвет [0..255]
                                                    //
        int RGB_BLUE;                               // синий цвет [0..255]
                                                    //
    public:
        int intersected_ind = -1;                   // порядковый номер объекта, с которым шар соприкоснулся
    public:
        circle()
        {}
        circle(int new_startX, int new_startY, int new_endX, int new_endY, int new_speed, int new_angle)        // параметризированный конструктор
        :   startX(new_startX)
        ,   startY(new_startY)
        ,   speed(new_speed)
        ,   angle(new_angle)
        {
            centerX = startX + sign(new_endX - new_startX) * minimum(absVal(new_startX - new_endX), absVal(new_startY - new_endY));
            centerY = startY + sign(new_endY - new_startY) * minimum(absVal(new_startX - new_endX), absVal(new_startY - new_endY));

            endX = centerX;
            endY = centerY;

            centerX = (startX + endX) / 2;
            centerY = (startY + endY) / 2;
            radius = minimum(absVal(startX - endX), absVal(startY - endY));
        }

        inline std::string get_name(){return name;}         // возврат имени фигуры

        inline int get_startX(){return startX;}             // возврат стартовой позиции по Ox.
        void set_startX(int newVal)                         // установка стартовой позиции по Oy.
        {
            startX = newVal;
            return;
        }

        inline int get_startY(){return startY;}             // возврат стартовой позиции по Oy.
        void set_startY(int newVal)                         // установка стартовой позиции по Oy.
        {
            startY = newVal;
            return;
        }

        inline int get_endX(){return endX;}                 // возврат конечной позиции по Ox.
        void set_endX(int newVal)                           // установка конечной позиции по Ox.
        {
            endX = newVal;
            return;
        }

        inline int get_endY(){return endY;}                 // возврат конечной позиции по Oy.
        void set_endY(int newVal)                           // установка конечной позиции по Oy.
        {
            endY = newVal;
            return;
        }

        inline int get_centerX(){return centerX;}           // возврат позиции центра круга по Ox.
        void set_centerX(int newVal)                        // установка позиции центра круга по Ox.
        {
            centerX = newVal;
            return;
        }

        inline int get_centerY(){return centerY;}           // возврат позиции центра круга по Oy.
        void set_centerY(int newVal)                        // установка позиции центра круга по Oy.
        {
            centerY = newVal;
            return;
        }

        inline int get_speed(){return speed;}               // возврат скорости движения круга
        void set_speed(int newVal)                          // установка скорости движения круга
        {
            speed = newVal;
        }

        inline int get_angle(){return angle;}              // возврат угла движения круга
        void set_angle(int newVal)                          // установка угла движения круга
        {
            angle = newVal;
            return;
        }

        inline int get_radius(){return radius;}             // возврат радиуса круга
        void set_radius(int newVal)                         // установка радиуса круга
        {
            radius = newVal;
            return;
        }

        inline int get_RGB_RED(){return RGB_RED;}           // возврат параметра красного цвета
        inline int get_RGB_GREEN(){return RGB_GREEN;}       // возврат парпметра зелёного цвета
        inline int get_RGB_BLUE(){return RGB_BLUE;}         // возврат параметра синего цвета
        void set_RGB(int R, int G, int B)                   // установка цвета круга
        {
            RGB_RED = R;
            RGB_GREEN = G;
            RGB_BLUE = B;
        }

        void update()
        {
            centerX = startX + sign(endX - startX) * minimum(absVal(startX - endX), absVal(startY - endY));
            centerY = startY + sign(endY - startY) * minimum(absVal(startX - endX), absVal(startY - endY));

            endX = centerX;
            endY = centerY;

            centerX = (startX + endX) / 2;
            centerY = (startY + endY) / 2;
        }

        void define_radius()
        {
            update();
            radius = absVal(centerX - startX);
        }

        void calculate()
        {
            int dist = speed * 0.3;

            centerX = centerX + dist * cos(pi * angle / 180);
            centerY = centerY - dist * sin(pi * angle / 180);

            startX = centerX - radius;
            startY = centerY - radius;
            endX = centerX + radius;
            endY = centerY + radius;
        }
};

#endif // CIRCLE_H_INCLUDED

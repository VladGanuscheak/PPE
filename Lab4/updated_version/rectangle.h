#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "figure.h"
#include "template_functions.h"

class rectangle: public figure
{
    private:
        const std::string name = "rectangle";         // имя фигуры
                                                    //
        int startX;                                 // позиция левого верхнего угла в проекции на ось Ox.
                                                    //
        int startY;                                 // позиция левого верхнего угла в проекции на ось Oy.
                                                    //
        int endX;                                   // позиция правого нижнего угла в проекции на ось Ox.
                                                    //
        int endY;                                   // позиция правого нижнего угла в проекции на ось Oy
                                                    //
        int centerX;                                // координата центра эллипса в проекции на ось Ox.
                                                    //
        int centerY;                                // координата центра эллипса в проекции на ось Oy.
                                                    //
        const int speed = 0;                        // скорость движения квадрата
                                                    //
        const int angle = 0;                        // угол движения квадрата
                                                    //
        const int radius = -1;                      // радиус квадрата = -1 (не существует)
                                                    //
        int RGB_RED;                                // красный цвет [0..255]
                                                    //
        int RGB_GREEN;                              // зелёный цвет [0..255]
                                                    //
        int RGB_BLUE;                               // синий цвет [0..255]
    public:
        rectangle()
        {}
        rectangle (int new_startX, int new_startY, int new_endX, int new_endY, int new_speed, int new_angle)        // параметризированный конструктор
        :   startX(new_startX)
        ,   startY(new_startY)
        ,   endX(new_endX)
        ,   endY(new_endY)
        ,   speed(new_speed)
        ,   angle(new_angle)
        {
            centerX = (startX + endX) / 2;
            centerY = (startY + endY) / 2;
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

        inline int get_centerX(){return centerX;}           // возврат позиции центра прямоугольника по Ox.
        void set_centerX(int newVal)                        // установка позиции центра прямоугольника по Ox.
        {
            centerX = newVal;
            return;
        }

        inline int get_centerY(){return centerY;}           // возврат позиции центра прямоугольника по Oy.
        void set_centerY(int newVal)                        // установка позиции центра прямоугольника по Oy.
        {
            centerY = newVal;
            return;
        }

        inline int get_speed(){return speed;}               // возврат скорости движения прямоугольника
        void set_speed(int newVal)                          // установка скорости движения прямоугольника
        {
            return;
        }

        inline int get_angle(){return radius;}              // возврат угла движения прямоугольника
        void set_angle(int newVal)                          // установка угла движения прямоугольника
        {
            return;
        }

        inline int get_radius(){return radius;}             // возврат радиуса прямоугольника
        void set_radius(int newVal)                         // установка радиуса прямоугольника = -1 всегда
        {
            return;
        }

        inline int get_RGB_RED(){return RGB_RED;}           // возврат параметра красного цвета
        inline int get_RGB_GREEN(){return RGB_GREEN;}       // возврат парпметра зелёного цвета
        inline int get_RGB_BLUE(){return RGB_BLUE;}         // возврат параметра синего цвета
        void set_RGB(int R, int G, int B)                   // установка цвета прямоугольника
        {
            RGB_RED = R;
            RGB_GREEN = G;
            RGB_BLUE = B;
        }
};


#endif // RECTANGLE_H_INCLUDED


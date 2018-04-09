#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <cmath>
#define pi 3.14
#include "figure.h"
#include "template_functions.h"

class circle: public figure
{
    private:
        const std::string name = "circle";          // ��� ������
                                                    //
        int startX;                                 // ������� ������ �������� ���� � �������� �� ��� Ox.
                                                    //
        int startY;                                 // ������� ������ �������� ���� � �������� �� ��� Oy.
                                                    //
        int endX;                                   // ������� ������� ������� ���� � �������� �� ��� Ox.
                                                    //
        int endY;                                   // ������� ������� ������� ���� � �������� �� ��� Oy
                                                    //
        int centerX;                                // ���������� ������ ����� � �������� �� ��� Ox.
                                                    //
        int centerY;                                // ���������� ������ ����� � �������� �� ��� Oy.
                                                    //
        int speed;                                  // �������� �������� �����
                                                    //
        int angle;                                  // ���� �������� �����
                                                    //
        int radius;                                 // ������ �����
                                                    //
        int RGB_RED;                                // ������� ���� [0..255]
                                                    //
        int RGB_GREEN;                              // ������ ���� [0..255]
                                                    //
        int RGB_BLUE;                               // ����� ���� [0..255]
                                                    //
    public:
        int intersected_ind = -1;                   // ���������� ����� �������, � ������� ��� �������������
    public:
        circle()
        {}
        circle(int new_startX, int new_startY, int new_endX, int new_endY, int new_speed, int new_angle)        // ������������������� �����������
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

        inline std::string get_name(){return name;}         // ������� ����� ������

        inline int get_startX(){return startX;}             // ������� ��������� ������� �� Ox.
        void set_startX(int newVal)                         // ��������� ��������� ������� �� Oy.
        {
            startX = newVal;
            return;
        }

        inline int get_startY(){return startY;}             // ������� ��������� ������� �� Oy.
        void set_startY(int newVal)                         // ��������� ��������� ������� �� Oy.
        {
            startY = newVal;
            return;
        }

        inline int get_endX(){return endX;}                 // ������� �������� ������� �� Ox.
        void set_endX(int newVal)                           // ��������� �������� ������� �� Ox.
        {
            endX = newVal;
            return;
        }

        inline int get_endY(){return endY;}                 // ������� �������� ������� �� Oy.
        void set_endY(int newVal)                           // ��������� �������� ������� �� Oy.
        {
            endY = newVal;
            return;
        }

        inline int get_centerX(){return centerX;}           // ������� ������� ������ ����� �� Ox.
        void set_centerX(int newVal)                        // ��������� ������� ������ ����� �� Ox.
        {
            centerX = newVal;
            return;
        }

        inline int get_centerY(){return centerY;}           // ������� ������� ������ ����� �� Oy.
        void set_centerY(int newVal)                        // ��������� ������� ������ ����� �� Oy.
        {
            centerY = newVal;
            return;
        }

        inline int get_speed(){return speed;}               // ������� �������� �������� �����
        void set_speed(int newVal)                          // ��������� �������� �������� �����
        {
            speed = newVal;
        }

        inline int get_angle(){return angle;}              // ������� ���� �������� �����
        void set_angle(int newVal)                          // ��������� ���� �������� �����
        {
            angle = newVal;
            return;
        }

        inline int get_radius(){return radius;}             // ������� ������� �����
        void set_radius(int newVal)                         // ��������� ������� �����
        {
            radius = newVal;
            return;
        }

        inline int get_RGB_RED(){return RGB_RED;}           // ������� ��������� �������� �����
        inline int get_RGB_GREEN(){return RGB_GREEN;}       // ������� ��������� ������� �����
        inline int get_RGB_BLUE(){return RGB_BLUE;}         // ������� ��������� ������ �����
        void set_RGB(int R, int G, int B)                   // ��������� ����� �����
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

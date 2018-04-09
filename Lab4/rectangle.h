#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "figure.h"
#include "template_functions.h"

class rectangle: public figure
{
    private:
        const std::string name = "rectangle";         // ��� ������
                                                    //
        int startX;                                 // ������� ������ �������� ���� � �������� �� ��� Ox.
                                                    //
        int startY;                                 // ������� ������ �������� ���� � �������� �� ��� Oy.
                                                    //
        int endX;                                   // ������� ������� ������� ���� � �������� �� ��� Ox.
                                                    //
        int endY;                                   // ������� ������� ������� ���� � �������� �� ��� Oy
                                                    //
        int centerX;                                // ���������� ������ ������� � �������� �� ��� Ox.
                                                    //
        int centerY;                                // ���������� ������ ������� � �������� �� ��� Oy.
                                                    //
        const int speed = 0;                        // �������� �������� ��������
                                                    //
        const int angle = 0;                        // ���� �������� ��������
                                                    //
        const int radius = -1;                      // ������ �������� = -1 (�� ����������)
                                                    //
        int RGB_RED;                                // ������� ���� [0..255]
                                                    //
        int RGB_GREEN;                              // ������ ���� [0..255]
                                                    //
        int RGB_BLUE;                               // ����� ���� [0..255]
    public:
        rectangle()
        {}
        rectangle (int new_startX, int new_startY, int new_endX, int new_endY, int new_speed, int new_angle)        // ������������������� �����������
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

        inline int get_centerX(){return centerX;}           // ������� ������� ������ �������������� �� Ox.
        void set_centerX(int newVal)                        // ��������� ������� ������ �������������� �� Ox.
        {
            centerX = newVal;
            return;
        }

        inline int get_centerY(){return centerY;}           // ������� ������� ������ �������������� �� Oy.
        void set_centerY(int newVal)                        // ��������� ������� ������ �������������� �� Oy.
        {
            centerY = newVal;
            return;
        }

        inline int get_speed(){return speed;}               // ������� �������� �������� ��������������
        void set_speed(int newVal)                          // ��������� �������� �������� ��������������
        {
            return;
        }

        inline int get_angle(){return radius;}              // ������� ���� �������� ��������������
        void set_angle(int newVal)                          // ��������� ���� �������� ��������������
        {
            return;
        }

        inline int get_radius(){return radius;}             // ������� ������� ��������������
        void set_radius(int newVal)                         // ��������� ������� �������������� = -1 ������
        {
            return;
        }

        inline int get_RGB_RED(){return RGB_RED;}           // ������� ��������� �������� �����
        inline int get_RGB_GREEN(){return RGB_GREEN;}       // ������� ��������� ������� �����
        inline int get_RGB_BLUE(){return RGB_BLUE;}         // ������� ��������� ������ �����
        void set_RGB(int R, int G, int B)                   // ��������� ����� ��������������
        {
            RGB_RED = R;
            RGB_GREEN = G;
            RGB_BLUE = B;
        }
};


#endif // RECTANGLE_H_INCLUDED


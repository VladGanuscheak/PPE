#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "figure.h"
#include "template_functions.h"

class square: public figure
{
    private:
        const std::string name = "square";         // ��� ������
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
        square()
        {}
        square(int new_startX, int new_startY, int new_endX, int new_endY, int new_speed, int new_angle)        // ������������������� �����������
        :   startX(new_startX)
        ,   startY(new_startY)
        {
            centerX = startX + sign(new_endX - new_startX) * minimum(absVal(new_startX - new_endX), absVal(new_startY - new_endY));
            centerY = startY + sign(new_endY - new_startY) * minimum(absVal(new_startX - new_endX), absVal(new_startY - new_endY));

            endX = centerX;
            endY = centerY;

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

        inline int get_centerX(){return centerX;}           // ������� ������� ������ �������� �� Ox.
        void set_centerX(int newVal)                        // ��������� ������� ������ �������� �� Ox.
        {
            centerX = newVal;
            return;
        }

        inline int get_centerY(){return centerY;}           // ������� ������� ������ �������� �� Oy.
        void set_centerY(int newVal)                        // ��������� ������� ������ �������� �� Oy.
        {
            centerY = newVal;
            return;
        }

        inline int get_speed(){return speed;}               // ������� �������� �������� ��������
        void set_speed(int newVal)                          // ��������� �������� �������� ��������
        {
            return;
        }

        inline int get_angle(){return radius;}              // ������� ���� �������� ��������
        void set_angle(int newVal)                          // ��������� ���� �������� ��������
        {
            return;
        }

        inline int get_radius(){return radius;}             // ������� ������� ��������
        void set_radius(int newVal)                         // ��������� ������� �������� = -1 ������
        {
            return;
        }

        inline int get_RGB_RED(){return RGB_RED;}           // ������� ��������� �������� �����
        inline int get_RGB_GREEN(){return RGB_GREEN;}       // ������� ��������� ������� �����
        inline int get_RGB_BLUE(){return RGB_BLUE;}         // ������� ��������� ������ �����
        void set_RGB(int R, int G, int B)                   // ��������� ����� ��������
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
};


#endif // SQUARE_H_INCLUDED

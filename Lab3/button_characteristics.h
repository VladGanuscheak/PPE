#ifndef BUTTON_CHARACTERISTICS_H_INCLUDED
#define BUTTON_CHARACTERISTICS_H_INCLUDED

/* ���������, � ������� �������� �������������� ������ */
typedef struct button_characteristics
{
   int horizontal_position;                                                // ������� ������ �������� ���� ������ �
                                                                           // �������� �� ��� Ox
                                                                           //
   int vertical_position;                                                  // ������� ������ �������� ���� ������ �
                                                                           // �������� �� ��� Oy
                                                                           //
   int width;                                                              // ���������� ����� ����� ������� � ������ �������
                                                                           // ������ � �������� �� ��� Ox
                                                                           //
   int height;                                                             // ���������� ����� ����� ������� � ������ �������
                                                                           // ������ � �������� �� ��� Oy
                                                                           //

   button_characteristics()                                                // ����������� �� ���������
   :  horizontal_position(0)
   ,  vertical_position(0)
   ,  width(0)
   ,  height(0)
   {}

   button_characteristics(int hor_pos, int vert_pos, int wid, int hei)     // ����������������� �����������
   :  horizontal_position(hor_pos)
   ,  vertical_position(vert_pos)
   ,  width(wid)
   ,  height(hei)
   {}
}bt;

#endif // BUTTON_CHARACTERISTICS_H_INCLUDED

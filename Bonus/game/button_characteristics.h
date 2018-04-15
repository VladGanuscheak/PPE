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
   int digit;                                                              // �����, ������������ �������
                                                                           //
   bool can_klick;                                                         // ������� - ����� ������, ����� - ������.
                                                                           //
   button_characteristics()                                                // ����������� �� ���������
   :  horizontal_position(0)
   ,  vertical_position(0)
   ,  width(0)
   ,  height(0)
   ,  digit(0)
   ,  can_klick(true)
   {}
   button_characteristics(int hor_pos, int vert_pos, int wid, int hei, int dig = 0, bool klick = true)     // ����������������� �����������
   :  horizontal_position(hor_pos)
   ,  vertical_position(vert_pos)
   ,  width(wid)
   ,  height(hei)
   ,  digit(dig)
   ,  can_klick(klick)
   {}
}bt;

#endif // BUTTON_CHARACTERISTICS_H_INCLUDED

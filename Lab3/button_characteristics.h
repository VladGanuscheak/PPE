#ifndef BUTTON_CHARACTERISTICS_H_INCLUDED
#define BUTTON_CHARACTERISTICS_H_INCLUDED

/* структура, в которой хранятся характеристики кнопки */
typedef struct button_characteristics
{
   int horizontal_position;                                                // позиция левого верхнего угла кнопки в
                                                                           // проекции на ось Ox
                                                                           //
   int vertical_position;                                                  // позиция левого верхнего угла кнопки в
                                                                           // проекции на ось Oy
                                                                           //
   int width;                                                              // расстояние между левым верхнем и правым верхнем
                                                                           // углами в проекции на ось Ox
                                                                           //
   int height;                                                             // расстояние между левым верхнем и правым верхнем
                                                                           // углами в проекции на ось Oy
                                                                           //

   button_characteristics()                                                // конструктор по умолчанию
   :  horizontal_position(0)
   ,  vertical_position(0)
   ,  width(0)
   ,  height(0)
   {}

   button_characteristics(int hor_pos, int vert_pos, int wid, int hei)     // параметризованный конструктор
   :  horizontal_position(hor_pos)
   ,  vertical_position(vert_pos)
   ,  width(wid)
   ,  height(hei)
   {}
}bt;

#endif // BUTTON_CHARACTERISTICS_H_INCLUDED

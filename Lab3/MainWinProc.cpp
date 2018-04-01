#include <windows.h>
#include <iostream>
#include <vector>
#include <string.h>

#include "defines.h"
#include "button_characteristics.h"
#include "functions.h"
#include "drawing.h"

/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp)
{
	static int StartX, StartY;
	static int EndX, EndY;
	static bool draw = false;

    static HWND radioBox[7];                                  // массив радиокнопок
                                                              //
    static HWND editColor;                                 // переменная, отвечающая за ввод текста пользователем
                                                              //
    bt rb[7];                                                 // массив структуры button_characteristics (bt)


    const char* name[7] = {                                   // имена кнопок (в их порядке)
                                                              //
                        "Rectangle",                          // прямоугольник
                                                              //
                        "Square",                             // квадрат
                                                              //
                        "Ellipse",                            // эллипс
                                                              //
                        "Circle",                             // круг
                                                              //
                        "Straight line",                      // прямая линия
                                                              //
                        "Polyline",                           // множество прямых линий
                                                              //
                        "Bezier curve",                       // кривая Безье
                    };

    RECT Rect;

    static bool ID_RECTANGLE_CHECKED = false;                // логическая переменная, указывающая на состояние прямоугольника
                                                             //
    static bool ID_SQUARE_CHECKED = false;                   // логическая переменная, указывающая на состояние квадрата
                                                             //
    static bool ID_ELLIPSE_CHECKED = false;                  // логическая переменная, указывающая на состояние эллипса
                                                             //
    static bool ID_CIRCLE_CHECKED = false;                   // логическая переменная, указывающая на состояние круга
                                                             //
    static bool ID_STRAIGHT_LINE_CHECKED = false;            // логическая переменная, указывающая на состояние прямой линии
                                                             //
    static bool ID_POLYLINE_CHECKED = false;                 // логическая переменная, указывающая на состояние множества соединённых линий
                                                             //
    static bool ID_BEZIER_CURVE_CHECKED = false;             // логическая переменная, указывающая на состояние кривой Безье


    static PAINTSTRUCT ps;
    static HDC hdc;

    bool fDraw = false;
    POINT ptPrevious;

    static std::vector<fig> figura;

    static std::vector<BezierSD> bez;

    static bool ignoreWindowSize = false;

    static POINT *BezierPointsArray = NULL;

    switch (msg)
    {
    case WM_CREATE: // создание окна
        GetClientRect(hw, &Rect);

        for(int i = 0; i < 7; i++)                          // динамическая расстановка характеристики (позиции) кнопок в rb[index]
        {
            rb[i] = bt(20, (Rect.bottom - 140) / 7 * i + 10 * i + 30, 110, (Rect.bottom - 140) / 7);
        }
        for(int i = 0; i < 7; i++)                          // динамическая расстановка кнопок на экране
        radioBox[i] = CreateWindow(
                     "button",                              // указатель на зарегистрированное имя класса
                                                            //
                     name[i],                               // указатель на имя окна
                                                            //
                     WS_CHILD | WS_VISIBLE| BS_RADIOBUTTON, // стиль окна
                                                            //
                     rb[i].horizontal_position,             // горизонтальная позиция окна
                                                            //
                     rb[i].vertical_position,               // вертикальная позиция окна
                                                            //
                     rb[i].width,                           // ширина окна
                                                            //
                     rb[i].height,                          // высота окна
                                                            //
                     hw,                                    // дескриптор родительского или окна владельца
                                                            //
                     (HMENU)i,                              // дескриптор меню или ID дочернего окна
                                                            //
                     NULL,                                  // дескриптор экземпляра приложения
                                                            //
                     NULL                                   // указатель на данные создания окна
                     );
         editColor = CreateWindow(
                                     "edit",
                                     "255 255 255",
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     20,
                                     rb[6].vertical_position + rb[6].height + 10,
                                     110,
                                     25,
                                     hw,
                                     NULL,
                                     NULL,
                                     NULL
                                     );
        return 0;
    case WM_COMMAND:
        switch(HIWORD(wp))
        {
            case 0:
                {
                char buf[256];
                switch (LOWORD(wp))
                {
                    case ID_RECTANGLE:
                    {
                        switch(ID_RECTANGLE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_RECTANGLE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_RECTANGLE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_RECTANGLE_CHECKED = (!ID_RECTANGLE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_RECTANGLE_CHECKED, hw);
                        break;
                    }
                    case ID_SQUARE:
                    {
                        switch(ID_SQUARE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_SQUARE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_SQUARE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_SQUARE_CHECKED = (!ID_SQUARE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_SQUARE_CHECKED, hw);
                        break;
                    }
                    case ID_ELLIPSE:
                    {
                        switch(ID_ELLIPSE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_ELLIPSE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_ELLIPSE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_ELLIPSE_CHECKED = (!ID_ELLIPSE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_ELLIPSE_CHECKED, hw);
                        break;
                    }
                    case ID_CIRCLE:
                    {
                        switch(ID_CIRCLE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_CIRCLE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_CIRCLE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_CIRCLE_CHECKED = (!ID_CIRCLE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_CIRCLE_CHECKED, hw);
                        break;
                    }
                    case ID_STRAIGHT_LINE:
                    {
                        switch(ID_STRAIGHT_LINE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_STRAIGHT_LINE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_STRAIGHT_LINE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_STRAIGHT_LINE_CHECKED = (!ID_STRAIGHT_LINE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_STRAIGHT_LINE_CHECKED, hw);
                        break;
                    }
                    case ID_POLYLINE:
                    {
                        switch(ID_POLYLINE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_POLYLINE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_POLYLINE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_POLYLINE_CHECKED = (!ID_POLYLINE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_POLYLINE_CHECKED, hw);
                        break;
                    }
                    case ID_BEZIER_CURVE:
                    {
                        switch(ID_BEZIER_CURVE_CHECKED)
                        {
                            case false:
                                //
                                for(int i = 0; i < 7; i++)
                                {
                                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                                }
                                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                                 &ID_SQUARE_CHECKED,
                                                 &ID_ELLIPSE_CHECKED,
                                                 &ID_CIRCLE_CHECKED,
                                                 &ID_STRAIGHT_LINE_CHECKED,
                                                 &ID_POLYLINE_CHECKED,
                                                 &ID_BEZIER_CURVE_CHECKED
                                                 );
                                //
                                SendMessage(GetDlgItem(hw, ID_BEZIER_CURVE), BM_SETCHECK, BST_CHECKED, NULL);
                                break;
                            default:
                                SendMessage(GetDlgItem(hw, ID_BEZIER_CURVE), BM_SETCHECK, BST_UNCHECKED, NULL);
                                break;
                        }
                        ID_BEZIER_CURVE_CHECKED = (!ID_BEZIER_CURVE_CHECKED);
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_BEZIER_CURVE_CHECKED, hw);
                        break;
                    }
                    case ID_FILE_EXIT: // MENU -> FILE -> EXIT
                    {
                        /* пользователь закрыл окно, программа может завершаться */
                        PostQuitMessage(0);
                        break;
                    }
                    case ID_EDIT_CREATE_RECTANGLE: // MENU -> EDIT -> CREATE -> RECTANGLE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_RECTANGLE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_RECTANGLE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        //check(ID_RECTANGLE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_CREATE_SQUARE: // MENU -> EDIT -> CREATE -> SQUARE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_SQUARE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_SQUARE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_SQUARE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_CREATE_ELLIPSE: // MENU -> EDIT -> CREATE -> ELLIPSE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_ELLIPSE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_ELLIPSE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_ELLIPSE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_CREATE_CIRCLE: // MENU -> EDIT -> CREATE -> CIRCLE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_CIRCLE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_CIRCLE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_CIRCLE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_CREATE_STRAIGHT_LINE: // MENU -> EDIT -> CREATE -> STRAIGHT LINE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_STRAIGHT_LINE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_STRAIGHT_LINE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_STRAIGHT_LINE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_CREATE_POLYLINE: // MENU -> EDIT -> CREATE -> POLYLLINE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_POLYLINE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_POLYLINE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_POLYLINE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_CREATE_BEZIER_CURVE: // MENU -> EDIT -> CREATE -> BEZIER CURVE
                    {
                        for(int i = 0; i < 7; i++)
                        {
                            SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                        }
                        defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                         &ID_SQUARE_CHECKED,
                                         &ID_ELLIPSE_CHECKED,
                                         &ID_CIRCLE_CHECKED,
                                         &ID_STRAIGHT_LINE_CHECKED,
                                         &ID_POLYLINE_CHECKED,
                                         &ID_BEZIER_CURVE_CHECKED
                                        );
                        SendMessage(GetDlgItem(hw, ID_BEZIER_CURVE), BM_SETCHECK, BST_CHECKED, NULL);
                        ID_BEZIER_CURVE_CHECKED = true;
                        SetFocus(hw);
                        prevSetted = false;
                        drawBezier = false;
                        if (BezierPointsArray)
                        {
                            delete[] BezierPointsArray;
                        }
                        //check(ID_BEZIER_CURVE_CHECKED, hw);
                        break;
                    }
                    case ID_EDIT_SET_WINDOW_SIZE_DEFAULT: // MENU -> EDIT -> SET -> WINDOW SIZE -> DEFAULT
                    {
                        MoveWindow(hw, START_POSITION_OX, START_POSITION_OY, DEFAULT_WINDOW_SIZE_OX, DEFAULT_WINDOW_SIZE_OY, TRUE);
                        break;
                    }
                    case ID_EDIT_SET_WINDOW_SIZE_MINIMUM: // MENU -> EDIT -> SET -> WINDOW SIZE -> MINIMUM
                    {
                        MoveWindow(hw, START_POSITION_OX, START_POSITION_OY, MIN_WINDOW_SIZE_OX, MIN_WINDOW_SIZE_OY, TRUE);
                        break;
                    }
                    case ID_EDIT_SET_WINDOW_SIZE_MAXIMUM: // MENU -> EDIT -> SET -> WINDOW SIZE -> MAXIMUM
                    {
                        MoveWindow(hw, START_POSITION_OX, START_POSITION_OY, MAX_WINDOW_SIZE_OX, MAX_WINDOW_SIZE_OY, TRUE);
                        break;
                    }
                    case ID_EDIT_SET_COLOR_RED: // MENU -> EDIT -> SET -> COLOR -> RED
                    {
                        R = 255; G = B = 0;
                        break;
                    }
                    case ID_EDIT_SET_COLOR_GREEN: // MENU -> EDIT -> SET -> COLOR -> GREEN
                    {
                        G = 255; R = B = 0;
                        break;
                    }
                    case ID_EDIT_SET_COLOR_BLUE: // MENU -> EDIT -> SET -> COLOR -> BLUE
                    {
                        B = 255; R = G = 0;
                        break;
                    }
                    case ID_EDIT_SET_COLOR_WHITE: // MENU -> EDIT -> SET -> COLOR -> WHITE
                    {
                        R = G = B = 255;
                        break;
                    }
                    case ID_EDIT_SET_COLOR_BLACK: // MENU -> EDIT -> SET -> COLOR -> BLACK
                    {
                        R = G = B = 0;
                        break;
                    }
                    case ID_EDIT_SET_COLOR_PROPER_COLOR:
                    {
                        char buf[] = "Enter in the field below 'Bezier curve' values of RGB";
                        MessageBox(hw,buf,"RGB",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_EDIT_SET_ZOOM_IN: // MENU -> EDIT -> SET -> ZOOM -> IN
                    {
                        break;
                    }
                    case ID_EDIT_SET_ZOOM_OUT: // MENU -> EDIT -> SET -> ZOOM -> OUT
                    {
                        break;
                    }
                    case ID_EDIT_SET_MOUSE_DEFAULT: // MENU -> EDIT -> SET -> MOUSE -> DEFAULT
                    {
                        break;
                    }
                    case ID_EDIT_SET_MOUSE_ERASER: // MENU -> EDIT -> SET -> MOUSE -> ERASER
                    {
                        break;
                    }
                    case ID_EDIT_SET_MOUSE_TASSEL: // MENU -> EDIT -> SET -> MOUSE -> TASSEL
                    {
                        break;
                    }
                    case ID_EDIT_UNDO: // MENU -> EDIT -> UNDO
                    {
                        draw = false;
                        if (figura.size())
                        {
                            figura.pop_back();
                        }
                        DrawAgain(hw);
                        break;
                    }
                    case ID_ABOUT_SETTING_WINDOW_SIZE: // MENU -> ABOUT -> SETTING WINDOW SIZE
                    {
                        char buf[] = "DEFAULT: 780x570\nMINIMUM: 560x470\nMAXIMUM: 1366X768";
                        MessageBox(hw,buf,"WINDOW SIZE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_CHOOSING_COLOR: // MENU -> ABOUT -> CHOOSING COLOR
                    {
                        char buf[] = "There are the following available colors:\nRED\nGREEN\nBLUE\nWHITE\nBLACK\n\nAlso it's possible to SET YOUR PROPER COLOR!!!";
                        MessageBox(hw,buf,"COLORS",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_RECTANGLE: // MENU -> ABOUT -> FIGURES -> RECTANGLE
                    {
                        char buf[] = "This figure is drawing by such primitives as lines.\nIt is possible to do, because we know the start and end points.\nIn a nutshell, MATH!!!";
                        MessageBox(hw,buf,"RECTANGLE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_SQUARE: // MENU -> ABOUT -> FIGURES -> SQUARE
                    {
                        char buf[] = "To draw this figure was used the same logic as in case of rectangle.\nThe difference is that the application calculates the minimal side.\nKnowing the start and end points it is easily to calculate the direction\nin which we will put the sides!";
                        MessageBox(hw,buf,"SQUARE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_ELLIPSE: // MENU -> ABOUT -> FIGURES -> ELLIPSE
                    {
                        char buf[] = "It is necessary only to know the start and end points of the rectangle\n in which the ellipse will be drawn exactly.\nThere is a built-in function to draw this figure!";
                        MessageBox(hw,buf,"ELLIPSE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_CIRCLE: // MENU -> ABOUT -> FIGURES -> CIRCLE
                    {
                        char buf[] = "It is necessary only to know the start and end points of the rectangle\n in which the ellipse will be drawn exactly.\nThere is a built-in function to draw this figure!\nThe difference with the drawing square is the necessity to\ncalculate the shortest side (as in the case of square)!";
                        MessageBox(hw,buf,"CIRCLE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_STRAIGHT_LINE: // MENU -> ABOUT -> FIGURES -> STRAIGHT LINE
                    {
                        char buf[] = "It is only necessary to know the start and end points.\nThere is a built-in function to draw this figure!";
                        MessageBox(hw,buf,"STRAIGHT LINE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_POLYLINE: // MENU -> ABOUT -> FIGURES -> POLYLINE
                    {
                        char buf[] = "There is the same logic as in the case of the straight line.\nThe difference is that it is necessary to keep in memory\nthe coordinate of the previous point!";
                        MessageBox(hw,buf,"SQUARE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_FIGURES_BEZIER_CURVE: // MENU -> ABOUT -> FIGURES -> BEZIER CURVE
                    {
                        char buf[] = "It is necessary to have the array of points and to interpolate them!";
                        MessageBox(hw,buf,"BEZIER CURVE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }
                    case ID_ABOUT_AUTHOR: // MENU -> ABOUT -> AUTHOR
                    {
                        char buf[] = "TUM FAF-161 STUDENT:\n(ro) Vlad Ganusceac\n(eng) Vlad Ganuscheak";
                        MessageBox(hw,buf,"ELLIPSE",MB_OK|MB_ICONINFORMATION);
                        break;
                    }

                    default: /* все остальные команды */
                        wsprintf(buf,"Command code: %d",LOWORD(wp));
                        MessageBox(hw,buf,"MessageBox",MB_OK|MB_ICONINFORMATION);
                }
            }
            break;
            case EN_UPDATE:
            {
                char buff[256];
                HWND editHandle = (HWND)lp;
                GetWindowText(editHandle, buff, 256);
                std::string s1 = "", s2 = "", s3 = "";
                int n = 0;
                bool space = true;
                for(int i = 0; i < strlen(buff); i++)
                {
                    if (buff[i] == ' ')
                    {
                        space = true;
                    }
                    else if (buff[i] >= '0' && buff[i] <= '9')
                    {
                        if (space)
                        {
                            n++;
                        }
                        space = false;
                        switch(n)
                        {
                            case 1:
                                s1 += buff[i];
                                break;
                            case 2:
                                s2 += buff[i];
                                break;
                            case 3:
                                s3 += buff[i];
                                break;
                        }
                    }
                }
                R = newColor(s1);
                G = newColor(s2);
                B = newColor(s3);
            }
            break;
        }
        return 0;
    case WM_GETMINMAXINFO: // done
    {
        if (!ignoreWindowSize)
        {
            LPMINMAXINFO lpMMI = (LPMINMAXINFO)lp;
            // *****************************************
            lpMMI->ptMinTrackSize.x = MIN_WINDOW_SIZE_OX; // установка минимальной ширины экрана
                                                          //
            lpMMI->ptMinTrackSize.y = MIN_WINDOW_SIZE_OY; // установка минимальной высоты экрана
            // *****************************************
            lpMMI->ptMaxTrackSize.x = MAX_WINDOW_SIZE_OX; // установка максимальной ширины экрана
                                                          //
            lpMMI->ptMaxTrackSize.y = MAX_WINDOW_SIZE_OY; // установка максимальной высоты экрана
        }
    }
    return 0;
    case WM_CHAR:
    {
        int iKey = LOWORD(wp);
        int shiftValue = GetKeyState(VK_SHIFT);
        int tabValue = GetKeyState(VK_TAB);
        if (shiftValue)
        {
            if (iKey == 'r' || iKey == 'R') // SHIFT + R
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_RECTANGLE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_RECTANGLE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
            }
            else if (iKey == 's' || iKey == 'S')
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_SQUARE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_SQUARE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
            }
            else if (iKey == 'e' || iKey == 'E')
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_ELLIPSE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_ELLIPSE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
            }
            else if (iKey == 'c' || iKey == 'C')
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_CIRCLE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_CIRCLE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
            }
            else if (iKey == 'l' || iKey == 'L')
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_STRAIGHT_LINE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_STRAIGHT_LINE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
            }
            else if (iKey == 'p' || iKey == 'P')
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_POLYLINE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_POLYLINE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
            }
            else if (iKey == 'b' || iKey == 'B')
            {
                for(int i = 0; i < 7; i++)
                {
                    SendMessage(GetDlgItem(hw, i), BM_SETCHECK, BST_UNCHECKED, NULL);
                }
                defaultBoolValue(&ID_RECTANGLE_CHECKED,
                                 &ID_SQUARE_CHECKED,
                                 &ID_ELLIPSE_CHECKED,
                                 &ID_CIRCLE_CHECKED,
                                 &ID_STRAIGHT_LINE_CHECKED,
                                 &ID_POLYLINE_CHECKED,
                                 &ID_BEZIER_CURVE_CHECKED
                                 );
                                //
                SendMessage(GetDlgItem(hw, ID_BEZIER_CURVE), BM_SETCHECK, BST_CHECKED, NULL);
                ID_BEZIER_CURVE_CHECKED = true;
                prevSetted = false;
                drawBezier = false;
                if (BezierPointsArray)
                {
                    delete[] BezierPointsArray;
                }
                break;
            }
        }
        if (tabValue)
        {
            if (iKey == 'd' || iKey == 'D')
            {
                MoveWindow(hw, START_POSITION_OX, START_POSITION_OY, DEFAULT_WINDOW_SIZE_OX, DEFAULT_WINDOW_SIZE_OY, TRUE);
            }
            else if (iKey == 'n' || iKey == 'N')
            {
                MoveWindow(hw, START_POSITION_OX, START_POSITION_OY, MIN_WINDOW_SIZE_OX, MIN_WINDOW_SIZE_OY, TRUE);
            }
            else if (iKey == 'm' || iKey == 'M')
            {
                MoveWindow(hw, START_POSITION_OX, START_POSITION_OY, MAX_WINDOW_SIZE_OX, MAX_WINDOW_SIZE_OY, TRUE);
            }
        }
    }
    return 0;
    case WM_KEYDOWN:
    {
        int iKey = LOWORD(wp);
        int ctrlValue = GetKeyState(VK_CONTROL);
        if (ctrlValue < 0)
        {
            if (iKey == 'x' || iKey == 'X') // CTRL + X
            {
                PostQuitMessage(0);
            }
            else if (iKey == 'z' || iKey == 'Z') // CTRL + Z
            {
                draw = false;
                if (figura.size())
                {
                    figura.pop_back();
                }
                DrawAgain(hw);
            }
        }
    }
    return 0;
    //
    //
    //



    case WM_LBUTTONDOWN:
		{
		    if (ID_RECTANGLE_CHECKED)
            {
                hdc = GetDC(hw);
                StartX = LOWORD(lp);
                StartY = HIWORD(lp);

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);


                MoveToEx(hdc, StartX, StartY, NULL);
                LineTo(hdc, EndX, StartY);
                MoveToEx(hdc, StartX, StartY, NULL);
                LineTo(hdc, StartX, EndY);

                draw = true;
                ReleaseDC(hw, hdc);
            }
            else if (ID_SQUARE_CHECKED)
            {
                hdc = GetDC(hw);
                StartX = LOWORD(lp);
                StartY = HIWORD(lp);

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);

                MoveToEx(hdc, StartX, StartY, NULL);
                LineTo(hdc, EndX, StartY);
                MoveToEx(hdc, StartX, StartY, NULL);
                LineTo(hdc, StartX, EndY);

                draw = true;
                ReleaseDC(hw, hdc);
            }
            else if (ID_ELLIPSE_CHECKED)
            {
                hdc = GetDC(hw);
                StartX = LOWORD(lp);
                StartY = HIWORD(lp);

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);

                int middleX = (StartX + EndX) / 2;
                int middleY = (StartY + EndY) / 2;
                int width = absVal(StartX - EndX) / 2;
                int height = absVal(StartY - EndY) / 2;

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX + width, middleY);
                MoveToEx(hdc, middleX, middleY,NULL);
                LineTo(hdc, middleX - width, middleY);

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY + height);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY - height);


                draw = true;
                ReleaseDC(hw, hdc);
            }
            else if (ID_CIRCLE_CHECKED)
            {
                hdc = GetDC(hw);
                StartX = LOWORD(lp);
                StartY = HIWORD(lp);

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);

                int width = absVal(StartX - EndX);
                int height = absVal(StartY - EndY);
                int minVal = minimum(width, height);

                int sgX = ((StartX > EndX) ? -1 : 1);
                int sgY = ((StartY > EndY) ? -1 : 1);

                int middleX = StartX + sgX * minVal / 2;
                int middleY = StartY + sgY * minVal / 2;

                int Val = minVal / 2;

                EndX = StartX + sgX * minVal;
                EndY = StartY + sgY * minVal;

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY + Val);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY - Val);

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX + Val, middleY);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX - Val, middleY);


                draw = true;
                ReleaseDC(hw, hdc);
            }
            else if (ID_STRAIGHT_LINE_CHECKED)
            {
                hdc = GetDC(hw);
                StartX = LOWORD(lp);
                StartY = HIWORD(lp);

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);

                MoveToEx(hdc, StartX, StartY, NULL);
                LineTo(hdc, EndX, EndY);

                draw = true;
                ReleaseDC(hw, hdc);
            }
            else if (ID_POLYLINE_CHECKED)
            {
                hdc = GetDC(hw);
                if (!prevSetted)
                {
                    StartX = LOWORD(lp);
                    StartY = HIWORD(lp);
                    prevSetted = true;
                }
                else
                {
                    StartX = prevX;
                    StartY = prevY;
                }

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);

                MoveToEx(hdc, StartX, StartY, NULL);
                LineTo(hdc, EndX, EndY);

                draw = true;
                ReleaseDC(hw, hdc);
            }
            else if (ID_BEZIER_CURVE_CHECKED)
            {
                hdc = GetDC(hw);

                StartX = LOWORD(lp);
                StartY = HIWORD(lp);

                EndX = LOWORD(lp);
                EndY = HIWORD(lp);

                if (!drawBezier)
                {
                    BezierPointsArray = new POINT[30]();

                    BezierPointsArray[0].x = StartX;
                    BezierPointsArray[0].y = StartX;

                    BezierPointsArray[1].x = EndX;
                    BezierPointsArray[1].y = EndY;

                    nBezierPoints = 2;
                    drawBezier = true;
                }
                else if (nBezierPoints < 30)
                {
                    BezierPointsArray[nBezierPoints].x = EndX;
                    BezierPointsArray[nBezierPoints].y = EndY;
                    nBezierPoints++;
                    drawBezier = true;
                }

                PolyBezier(hdc, BezierPointsArray, nBezierPoints);
                PolyBezierTo(hdc, BezierPointsArray, nBezierPoints);

                draw = true;
                ReleaseDC(hw, hdc);
            }
		}
		return 0;

	case WM_MOUSEMOVE:

		hdc = GetDC(hw);
		if(draw)
		{
		    if (ID_RECTANGLE_CHECKED)
		    {
		        drawPrimitives::figureRectangle::SetRectangle(hdc, &StartX, &StartY, &EndX, &EndY, lp);
		    }
		    else if (ID_SQUARE_CHECKED)
            {
                drawPrimitives::figureSquare::SetSquare(hdc, &StartX, &StartY, &EndX, &EndY, lp);
            }
            else if (ID_ELLIPSE_CHECKED)
            {
                drawPrimitives::FigureEllipse::SetEllipse(hdc, &StartX, &StartY, &EndX, &EndY, lp);
            }
            else if (ID_CIRCLE_CHECKED)
            {
                drawPrimitives::FigureCircle::SetCircle(hdc, &StartX, &StartY, &EndX, &EndY, lp);
            }
            else if (ID_STRAIGHT_LINE_CHECKED)
            {
                drawPrimitives::FigureStraightLine::SetStaightLine(hdc, &StartX, &StartY, &EndX, &EndY, lp);
            }
            else if (ID_POLYLINE_CHECKED)
            {
                drawPrimitives::FigurePolyline::SetPolyline(hdc, &StartX, &StartY, &EndX, &EndY, lp);
            }
            else if (ID_BEZIER_CURVE_CHECKED)
            {
                drawPrimitives::FigureBezierCurve::SetBezierCurve(hdc, BezierPointsArray, nBezierPoints);
            }
		}
		break;

	case WM_LBUTTONUP:

		hdc = GetDC(hw);

        if (draw)
		{
		    EndX = LOWORD(lp);
            EndY = HIWORD(lp);

            if (ID_RECTANGLE_CHECKED)
            {
                drawPrimitives::figureRectangle::drawRectangle(hdc, fig("rectangle", StartX, StartY, EndX, EndY));
                figura.push_back(fig("rectangle", StartX, StartY, EndX, EndY));
                figura[figura.size() - 1].R = R;
                figura[figura.size() - 1].G = G;
                figura[figura.size() - 1].B = B;
                FillRect(hdc, &figura[figura.size() - 1].r, (HBRUSH)CreateSolidBrush(RGB(R, G, B)));
                DrawAgain(hw);
            }
            else if (ID_SQUARE_CHECKED)
            {
                int minVal = minimum(absVal(StartX - EndX), absVal(StartY - EndY));
                int sgX = ((EndX < StartX) ? -1 : 1);
                int sgY = ((EndY < StartY) ? -1 : 1);
                drawPrimitives::figureSquare::drawSquare(hdc, fig("square", StartX, StartY, StartX + sgX * minVal, StartY + sgY * minVal));
                figura.push_back(fig("square", StartX, StartY, StartX + sgX * minVal, StartY + sgY * minVal));
                figura[figura.size() - 1].R = R;
                figura[figura.size() - 1].G = G;
                figura[figura.size() - 1].B = B;
                FillRect(hdc, &figura[figura.size() - 1].r, (HBRUSH)CreateSolidBrush(RGB(R, G, B)));
                DrawAgain(hw);
            }
            else if (ID_ELLIPSE_CHECKED)
            {
                drawPrimitives::FigureEllipse::drawEllipse(hdc, fig("ellipse", StartX, StartY, EndX, EndY));
                figura.push_back(fig("ellipse", StartX, StartY, EndX, EndY));
                figura[figura.size() - 1].R = R;
                figura[figura.size() - 1].G = G;
                figura[figura.size() - 1].B = B;
                RECT r = figura[figura.size() - 1].r;
                HBRUSH hbr=CreateSolidBrush(RGB(R, G, B));
                HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
                Ellipse(hdc, r.left - 1, r.top - 1, r.right + 1, r.bottom + 1);
                SelectObject(hdc,hOld);
                DeleteObject(hbr);
                DrawAgain(hw);
            }
            else if (ID_CIRCLE_CHECKED)
            {
                int minVal = minimum(absVal(StartX - EndX), absVal(StartY - EndY));
                int sgX = ((EndX < StartX) ? -1 : 1);
                int sgY = ((EndY < StartY) ? -1 : 1);
                EndX = StartX + sgX * minVal;
                EndY = StartY + sgY * minVal;
                drawPrimitives::FigureCircle::drawCircle(hdc, fig("circle", StartX, StartY, EndX, EndY));
                figura.push_back(fig("circle", StartX, StartY, EndX, EndY));
                figura[figura.size() - 1].R = R;
                figura[figura.size() - 1].G = G;
                figura[figura.size() - 1].B = B;
                RECT r = figura[figura.size() - 1].r;
                HBRUSH hbr=CreateSolidBrush(RGB(R, G, B));
                HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
                Ellipse(hdc, r.left - 1, r.top - 1, r.right + 1, r.bottom + 1);
                SelectObject(hdc,hOld);
                DeleteObject(hbr);
                DrawAgain(hw);
            }
            else if (ID_STRAIGHT_LINE_CHECKED)
            {
                drawPrimitives::FigureStraightLine::SetStaightLine(hdc, &StartX, &StartY, &EndX, &EndY, lp);
                figura.push_back(fig("straight_line", StartX, StartY, EndX, EndY));
                DrawAgain(hw);
            }
            else if (ID_POLYLINE_CHECKED)
            {
                drawPrimitives::FigurePolyline::SetPolyline(hdc, &StartX, &StartY, &EndX, &EndY, lp);
                prevX = EndX;
                prevY = EndY;
                figura.push_back(fig("polyline", StartX, StartY, EndX, EndY));
                DrawAgain(hw);
            }
            else if (ID_BEZIER_CURVE_CHECKED)
            {
                drawPrimitives::FigureBezierCurve::SetBezierCurve(hdc, BezierPointsArray, nBezierPoints);
                figura.push_back(fig("bezier_curve", StartX, StartY, EndX, EndY));
                bez.push_back(BezierSD(nBezierPoints, BezierPointsArray, figura.size() - 1));
                DrawAgain(hw);
            }
            draw = false;
            ReleaseDC(hw, hdc);
		}
    return 0;
    case WM_SIZE: // done
    {
        int wWidth = LOWORD(lp) - 90;
        int wLength = HIWORD(lp) - 90;
        for(int i = 0; i < 7; i++)
        {
            rb[i] = bt(20, (wLength - 140) / 7 * i + 10 * i + 30, 110, (wLength - 140) / 7);
        }
        for(int i = 0; i < 7; i++)
        {
            MoveWindow(radioBox[i], rb[i].horizontal_position, rb[i].vertical_position, rb[i].width, rb[i].height, TRUE);
        }
        MoveWindow(editColor, 20, rb[6].vertical_position + rb[6].height + 10, 110, 25, TRUE);
    }
    return 0;



    case WM_PAINT:
    {
        hdc = BeginPaint(hw, &ps);

        for(int i = 0; i < figura.size(); i++)
        {
            if (!strcmp(figura[i].name, "rectangle"))
            {
                drawPrimitives::figureRectangle::drawRectangle(hdc, figura[i]);
                FillRect(hdc, &figura[i].r, (HBRUSH)CreateSolidBrush(RGB(figura[i].R, figura[i].G, figura[i].B)));
            }
            else if (!strcmp(figura[i].name, "square"))
            {
                drawPrimitives::figureSquare::drawSquare(hdc, figura[i]);
                FillRect(hdc, &figura[i].r, (HBRUSH)CreateSolidBrush(RGB(figura[i].R, figura[i].G, figura[i].B)));
            }
            else if (!strcmp(figura[i].name, "ellipse"))
            {
                drawPrimitives::FigureEllipse::drawEllipse(hdc, figura[i]);
                RECT r = figura[i].r;
                HBRUSH hbr=CreateSolidBrush(RGB(figura[i].R, figura[i].G, figura[i].B));
                HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
                Ellipse(hdc, r.left - 1, r.top - 1, r.right + 1, r.bottom + 1);
                SelectObject(hdc,hOld);
                DeleteObject(hbr);
            }
            else if (!strcmp(figura[i].name, "circle"))
            {
                drawPrimitives::FigureCircle::drawCircle(hdc, figura[i]);
                figura[figura.size() - 1].R = R;
                figura[figura.size() - 1].G = G;
                figura[figura.size() - 1].B = B;
                RECT r = figura[i].r;
                HBRUSH hbr=CreateSolidBrush(RGB(figura[i].R, figura[i].G, figura[i].B));
                HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
                Ellipse(hdc, r.left - 1, r.top - 1, r.right + 1, r.bottom + 1);
                SelectObject(hdc,hOld);
                DeleteObject(hbr);
            }
            else if (!strcmp(figura[i].name, "straight_line"))
            {
                drawPrimitives::FigureStraightLine::drawStraightLine(hdc, figura[i]);
            }
            else if (!strcmp(figura[i].name, "polyline"))
            {
                drawPrimitives::FigurePolyline::drawPolyline(hdc, figura[i]);
            }
            else if (!strcmp(figura[i].name, "bezier_curve"))
            {
                drawPrimitives::FigureBezierCurve::drawBezierCurve(hdc, bez[i]);
            }
        }
        EndPaint(hw, &ps);
    }
    return 0;

    case WM_DESTROY: // done
        /* пользователь закрыл окно, программа может завершаться */
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hw,msg,wp,lp);
    }
}

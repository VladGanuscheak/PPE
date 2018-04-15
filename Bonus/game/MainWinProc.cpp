#include <windows.h>
#include <random>
#include <ctime>
#include <cstdlib>
#include "defines.h"
#include "button_characteristics.h"

int minimum(int a, int b)
{
    return ((a < b) ? a : b);
}
bool valid(bt btm[], int v)
{
    int x = v / 9;
    int y = v % 9;
    int arr[10] = {0};
    for(int i = 0; i < 9; i++)
    {
        arr[btm[x * 9 + i].digit]++;
    }
    for(int i = 1; i < 10; i++)
    if (arr[i] != 1)
    {
        return false;
    }
    for(int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }


    int xi = x / 3 * 3;
    int yj = y / 3 * 3;
    for(int i = xi; i < xi + 3; i++)
    {
        for(int j = yj; j < yj + 3; j++)
        {
            arr[btm[i * 9 + j].digit]++;
        }
    }
    for(int i = 1; i < 10; i++)
    if (arr[i] != 1)
    {
        return false;
    }
    if (v < 80) return valid(btm ,v + 1);
    else return true;
}
bool can_put(bt btm[], int x, int y, int val)
{
    int arr[10] = {0};
    for(int i = 0; i < 9; i++)
    {
        arr[btm[x * 9 + i].digit]++;
    }
    if (arr[val])
    {
        return false;
    }
    for(int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    for(int i = 0; i < 9; i++)
    {
        arr[btm[i * 9 + y].digit]++;
    }
    if (arr[val])
    {
        return false;
    }
    for(int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }


    int xi = x / 3 * 3;
    int yj = y / 3 * 3;
    for(int i = xi; i < xi + 3; i++)
    {
        for(int j = yj; j < yj + 3; j++)
        {
            arr[btm[i * 9 + j].digit]++;
        }
    }

    if (arr[val])
    {
        return false;
    }
    return true;
}



/* процедура обработки сообщений дл€ главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    static HWND cell[81], button1;
    static bt btm[81], verif;
    RECT Rect;

    switch (msg)
    {
    case WM_CREATE:
        {
            GetClientRect(hw, &Rect);

            static HFONT hFont = CreateFont (
                              17,                              // высота шрифта
                                                               //
                              0,                               // средн€€ ширина символа
                                                               //
                              0,                               // угол наклона
                                                               //
                              0,                               // угол ориентации базисной линии
                                                               //
                              FW_DONTCARE,                     // толщина шрифта
                                                               //
                              TRUE,                           // описатель параметра курсивного шрифта
                                                               //
                              TRUE,                           // описатель параметра подчеркивани€
                                                               //
                              FALSE,                           // описатель параметра зачеркивани€
                                                               //
                              ANSI_CHARSET,                    // идентификатор набора символов
                                                               //
                              OUT_TT_PRECIS,                   // точность вывода
                                                               //
                              CLIP_DEFAULT_PRECIS,             // точность отсечени€
                                                               //
                              DEFAULT_QUALITY,                 // качество вывода
                                                               //
                              DEFAULT_PITCH | FF_DONTCARE,     // шаг между символами шрифта и семейство
                                                               //
                              TEXT("Consolas")                 // им€ гарнитуры шрифта
                              );

            int wWidth = Rect.right - 90;
            int wLength = Rect.bottom - 90;
            int magic = minimum(wWidth, wLength) / 9 - 2;
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    btm[i * 9 + j] = bt(20 + magic * (j + 1) + 5 * j, 20 + magic * (i + 1) + 5 * i, magic, magic);
                }
            }
            /* при создании окна внедр€ем в него кнопочку */
            for(int i = 0; i < 81; i++)
            cell[i] = CreateWindow(
                        "button",                           // указатель на зарегистрированное им€ класса
                                                            //
                        "0",                                // указатель на им€ окна
                                                            //
                        WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // стиль окна
                                                            //
                        btm[i].horizontal_position,         // горизонтальна€ позици€ окна
                                                            //
                        btm[i].vertical_position,           // вертикальна€ позици€ окна
                                                            //
                        btm[i].width,                       // ширина окна
                                                            //
                        btm[i].height,                      // высота окна
                                                            //
                        hw,                                 // дескриптор родительского или окна владельца
                                                            //
                        (HMENU)i,                           // дескриптор меню или ID дочернего окна
                                                            //
                        NULL,                               // дескриптор экземпл€ра приложени€
                                                            //
                        NULL                                // указатель на данные создани€ окна
                        );
        /* стиль WS_CHILD означает, что это дочернее окно и дл€ него
        вместо дескриптора меню будет передан целочисленный идентификатор,
        который будет использоватьс€ дочерним окном дл€ оповещени€
        родительского окна через WM_COMMAND */
        button1 = CreateWindow(
                        "button",                           // указатель на зарегистрированное им€ класса
                                                            //
                        "AC",                               // указатель на им€ окна
                                                            //
                        WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // стиль окна
                                                            //
                        Rect.right - 20,                    // горизонтальна€ позици€ окна
                                                            //
                        20,                                 // вертикальна€ позици€ окна
                                                            //
                        15,                                 // ширина окна
                                                            //
                        15,                                 // высота окна
                                                            //
                        hw,                                 // дескриптор родительского или окна владельца
                                                            //
                        (HMENU)ID_BUTTON1,                  // дескриптор меню или ID дочернего окна
                                                            //
                        NULL,                               // дескриптор экземпл€ра приложени€
                                                            //
                        NULL                                // указатель на данные создани€ окна
                        );
            std::mt19937 rnd(time(NULL));
            int n = 20;
            while(n > 0)
            {
                int x = rnd() % 9;
                int y = rnd() % 9;
                if (btm[x].can_klick)
                {
                    if (!btm[x * 9 + y].digit)
                    while(true)
                    {
                        int val = rnd() % 9 + 1;
                        if (can_put(btm, x, y, val))
                        {
                            btm[x * 9 + y].can_klick = false;
                            btm[x * 9 + y].digit = val;
                            n--;
                            SendMessage(cell[x * 9 + y], WM_SETFONT, (WPARAM)hFont, TRUE);
                            //HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
                            //SetClassLongPtr(cell[x * 9 + y], GCLP_HBRBACKGROUND, (UINT)brush);
                            break;
                        }
                    }
                }
            }
            for(int i = 0; i < 81; i++)
            {
                if (!btm[i].can_klick)
                {
                    switch(btm[i].digit)
                    {
                        case 0:
                            SetWindowText(cell[i], "0");
                            break;
                        case 1:
                            SetWindowText(cell[i], "1");
                            break;
                        case 2:
                            SetWindowText(cell[i], "2");
                            break;
                        case 3:
                            SetWindowText(cell[i], "3");
                            break;
                        case 4:
                            SetWindowText(cell[i], "4");
                            break;
                        case 5:
                            SetWindowText(cell[i], "5");
                            break;
                        case 6:
                            SetWindowText(cell[i], "6");
                            break;
                        case 7:
                            SetWindowText(cell[i], "7");
                            break;
                        case 8:
                            SetWindowText(cell[i], "8");
                            break;
                        case 9:
                            SetWindowText(cell[i], "9");
                            break;
                    }
                }
            }
        }
        return 0;
    case WM_COMMAND:
        if (HIWORD(wp)==0)
        {
            char buf[256];
            for(int i = 0; i < 81; i++)
            {
                if (LOWORD(wp) == i && btm[i].can_klick)
                {
                    btm[i].digit = (btm[i].digit + 1) % 10;
                    switch(btm[i].digit)
                    {
                        case 0:
                            SetWindowText(cell[i], "0");
                            break;
                        case 1:
                            SetWindowText(cell[i], "1");
                            break;
                        case 2:
                            SetWindowText(cell[i], "2");
                            break;
                        case 3:
                            SetWindowText(cell[i], "3");
                            break;
                        case 4:
                            SetWindowText(cell[i], "4");
                            break;
                        case 5:
                            SetWindowText(cell[i], "5");
                            break;
                        case 6:
                            SetWindowText(cell[i], "6");
                            break;
                        case 7:
                            SetWindowText(cell[i], "7");
                            break;
                        case 8:
                            SetWindowText(cell[i], "8");
                            break;
                        case 9:
                            SetWindowText(cell[i], "9");
                            break;
                    }
                    return 0;
                }
            }
            switch (LOWORD(wp))
            {
                case ID_BUTTON1:
                    if (valid(btm, 0))
                    {
                        char buf[] = "Congratulations! Your SUDOKU is ACCEPTED!!!";
                        MessageBox(hw,buf,"AC",MB_OK|MB_ICONINFORMATION);
                    }
                    else
                    {
                        char buf[] = "Try another one time!!!";
                        MessageBox(hw,buf,"Wrong answer",MB_OK|MB_ICONINFORMATION);
                    }
                    break;
                case ID_EDIT_RESIZE_WINDOW_430X430:
                    MoveWindow(hw, 0, 0, 430, 430, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_460X460:
                    MoveWindow(hw, 0, 0, 460, 460, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_512X512:
                    MoveWindow(hw, 0, 0, 512, 512, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_620X620:
                    MoveWindow(hw, 0, 0, 620, 620, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_768X768:
                    MoveWindow(hw, 0, 0, 768, 768, TRUE);
                    break;
                case ID_FILE_VERIFY:
                    if (valid(btm, 0))
                    {
                        char buf[] = "Congratulations! Your SUDOKU is ACCEPTED!!!";
                        MessageBox(hw,buf,"AC",MB_OK|MB_ICONINFORMATION);
                    }
                    else
                    {
                        char buf[] = "Try another one time!!!";
                        MessageBox(hw,buf,"Wrong answer",MB_OK|MB_ICONINFORMATION);
                    }
                    break;
                case ID_FILE_EXIT:
                    PostQuitMessage(0);
                    break;
                default: /* все остальные команды */
                    wsprintf(buf,"Unchangeable field!");
                    MessageBox(hw,buf,"MessageBox",MB_OK|MB_ICONINFORMATION);
            }
        }
        return 0;
    case WM_GETMINMAXINFO:
        {
            LPMINMAXINFO lpMMI = (LPMINMAXINFO)lp;
            lpMMI->ptMinTrackSize.x = MIN_WINDOW_SIZE_OX;
            lpMMI->ptMinTrackSize.y = MIN_WINDOW_SIZE_OY;
        }
        return 0;
    case WM_WINDOWPOSCHANGING:
        ((LPWINDOWPOS)lp)->cx = ((LPWINDOWPOS)lp)->cy;
        ((LPWINDOWPOS)lp)->cy = ((LPWINDOWPOS)lp)->cx;
        return 0;
    case WM_SIZE:
        {
            int wWidth = LOWORD(lp) - 90;
            int wLength = HIWORD(lp) - 90;
            int magic = minimum(wWidth, wLength) / 9 - 2;
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    btm[i * 9 + j] = bt(20 + magic * j + 5 * j, 20 + magic * i + 5 * i, magic, magic, btm[i * 9 + j].digit, btm[i * 9 + j].can_klick);
                }
            }
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    if (j > 2) btm[i * 9 + j].horizontal_position += 5;
                    if (j > 5) btm[i * 9 + j].horizontal_position += 5;
                    if (i > 2) btm[i * 9 + j].vertical_position += 5;
                    if (i > 5) btm[i * 9 + j].vertical_position += 5;
                }
            }
            for(int i = 0; i < 81; i++)
            {
                MoveWindow(cell[i],btm[i].horizontal_position,btm[i].vertical_position,btm[i].width,btm[i].height,TRUE);
            }
            MoveWindow(button1, magic * 9 + 80, 20, magic, magic, TRUE);
        }
        return 0;
        case WM_CHAR:
            {
                int iKey = LOWORD(wp);
                int shiftValue = GetKeyState(VK_SHIFT);
                if(shiftValue)
                {
                    if (iKey == (int)('s') || iKey == (int)('S'))
                    {
                        if (valid(btm, 0))
                        {
                            char buf[] = "Congratulations! Your SUDOKU is ACCEPTED!!!";
                            MessageBox(hw,buf,"AC",MB_OK|MB_ICONINFORMATION);
                        }
                        else
                        {
                            char buf[] = "Try another one time!!!";
                            MessageBox(hw,buf,"Wrong answer",MB_OK|MB_ICONINFORMATION);
                        }
                        break;
                    }
                    if (iKey == (int)('x') || iKey == (int)('X'))
                    {
                        PostQuitMessage(0);
                        break;
                    }
                }
                return 0;
            }
    case WM_DESTROY:
        /* пользователь закрыл окно, программа может завершатьс€ */
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hw,msg,wp,lp);
}

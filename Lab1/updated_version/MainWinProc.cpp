#include <windows.h>
#include "defines.h"
#include "button_characteristics.h"

/* процедура обработки сообщений дл€ главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    static HWND button1, button2;
    static bt bt1(25, 30, 100, 90);
    static bt bt2(135, 30, 100, 90);
    switch (msg)
    {
    case WM_CREATE:
        /* при создании окна внедр€ем в него кнопочку */
        button1 = CreateWindow(
                     "button",                           // указатель на зарегистрированное им€ класса
                                                         //
                     "My button1",                       // указатель на им€ окна
                                                         //
                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // стиль окна
                                                         //
                     bt1.horizontal_position,            // горизонтальна€ позици€ окна
                                                         //
                     bt1.vertical_position,              // вертикальна€ позици€ окна
                                                         //
                     bt1.width,                          // ширина окна
                                                         //
                     bt1.height,                         // высота окна
                                                         //
                     hw,                                 // дескриптор родительского или окна владельца
                                                         //
                     (HMENU)ID_BUTTON1,                  // дескриптор меню или ID дочернего окна
                                                         //
                     NULL,                               // дескриптор экземпл€ра приложени€
                                                         //
                     NULL                                // указатель на данные создани€ окна
                     );
        /* стиль WS_CHILD означает, что это дочернее окно и дл€ него
        вместо дескриптора меню будет передан целочисленный идентификатор,
        который будет использоватьс€ дочерним окном дл€ оповещени€
        родительского окна через WM_COMMAND */
                button2 = CreateWindow(
                     "button",                           // указатель на зарегистрированное им€ класса
                                                         //
                     "My button2",                       // указатель на им€ окна
                                                         //
                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // стиль окна
                                                         //
                     bt2.horizontal_position,            // горизонтальна€ позици€ окна
                                                         //
                     bt2.vertical_position,              // вертикальна€ позици€ окна
                                                         //
                     bt2.width,                          // ширина окна
                                                         //
                     bt2.height,                         // высота окна
                                                         //
                     hw,                                 // дескриптор родительского или окна владельца
                                                         //
                     (HMENU)ID_BUTTON2,                  // дескриптор меню или ID дочернего окна
                                                         //
                     NULL,                               // дескриптор экземпл€ра приложени€
                                                         //
                     NULL                                // указатель на данные создани€ окна
                     );
        return 0;
    case WM_COMMAND:
        if (HIWORD(wp)==0)
        {
            char buf[256];
            switch (LOWORD(wp))
            {
                case ID_BUTTON2:
                    {
                        char bt2_message[] = "The clicked button now has Consolas style text ;)";
    HFONT hFont = CreateFont (
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
                        SendMessage(button2, WM_SETFONT, (WPARAM)hFont, TRUE);
                        MessageBox(hw, bt2_message, "Special message", MB_OKCANCEL);
                    }
                    break;
                case ID_FILE_EXIT:  /* команда меню Exit */
                    PostQuitMessage(0);
                    break;
                case ID_EDIT_RESIZE_BUTTON1_DEFAULT:
                    bt1 = bt(25, 30, 100, 90);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case ID_EDIT_RESIZE_BUTTON1_BIGGER:
                    bt1 = bt(25, 30, 120, 105);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case ID_EDIT_RESIZE_BUTTON1_SMALLER:
                    bt1 = bt(25, 30, 80, 70);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case ID_EDIT_RESIZE_BUTTON2_DEFAULT:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 30;
                        bt2 = bt(135, 30, 100, 90);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_EDIT_RESIZE_BUTTON2_BIGGER:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 30;
                        bt2 = bt(135, 30, 120, 105);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_EDIT_RESIZE_BUTTON2_SMALLER:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 30;
                        bt2 = bt(135, 30, 80, 70);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_EDIT_RESIZE_WINDOW_450X300:
                    MoveWindow(hw, 0, 0, 450, 300, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_550X420:
                    MoveWindow(hw, 0, 0, 550, 420, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_700X512:
                    MoveWindow(hw, 0, 0, 700, 512, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_800X600:
                    MoveWindow(hw, 0, 0, 800, 600, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_1012X720:
                    MoveWindow(hw, 0, 0, 1012, 700, TRUE);
                    break;
                default: /* все остальные команды */
                    wsprintf(buf,"Command code: %d",LOWORD(wp));
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
    case WM_SIZE:
        {

            int xClient = LOWORD(lp);
            int yClient = HIWORD(lp);
            MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
            MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
        }
        return 0;
    case WM_DESTROY:
        /* пользователь закрыл окно, программа может завершатьс€ */
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hw,msg,wp,lp);
}

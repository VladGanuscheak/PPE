#include <windows.h>
#include "defines.h"
#include "button_characteristics.h"

/* ��������� ��������� ��������� ��� �������� ���� */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    static HWND button1, button2;
    static bt bt1(25, 30, 100, 90);
    static bt bt2(135, 30, 100, 90);
    switch (msg)
    {
    case WM_CREATE:
        /* ��� �������� ���� �������� � ���� �������� */
        button1 = CreateWindow(
                     "button",                           // ��������� �� ������������������ ��� ������
                                                         //
                     "My button1",                       // ��������� �� ��� ����
                                                         //
                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // ����� ����
                                                         //
                     bt1.horizontal_position,            // �������������� ������� ����
                                                         //
                     bt1.vertical_position,              // ������������ ������� ����
                                                         //
                     bt1.width,                          // ������ ����
                                                         //
                     bt1.height,                         // ������ ����
                                                         //
                     hw,                                 // ���������� ������������� ��� ���� ���������
                                                         //
                     (HMENU)ID_BUTTON1,                  // ���������� ���� ��� ID ��������� ����
                                                         //
                     NULL,                               // ���������� ���������� ����������
                                                         //
                     NULL                                // ��������� �� ������ �������� ����
                     );
        /* ����� WS_CHILD ��������, ��� ��� �������� ���� � ��� ����
        ������ ����������� ���� ����� ������� ������������� �������������,
        ������� ����� �������������� �������� ����� ��� ����������
        ������������� ���� ����� WM_COMMAND */
                button2 = CreateWindow(
                     "button",                           // ��������� �� ������������������ ��� ������
                                                         //
                     "My button2",                       // ��������� �� ��� ����
                                                         //
                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // ����� ����
                                                         //
                     bt2.horizontal_position,            // �������������� ������� ����
                                                         //
                     bt2.vertical_position,              // ������������ ������� ����
                                                         //
                     bt2.width,                          // ������ ����
                                                         //
                     bt2.height,                         // ������ ����
                                                         //
                     hw,                                 // ���������� ������������� ��� ���� ���������
                                                         //
                     (HMENU)ID_BUTTON2,                  // ���������� ���� ��� ID ��������� ����
                                                         //
                     NULL,                               // ���������� ���������� ����������
                                                         //
                     NULL                                // ��������� �� ������ �������� ����
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
                              17,                              // ������ ������
                                                               //
                              0,                               // ������� ������ �������
                                                               //
                              0,                               // ���� �������
                                                               //
                              0,                               // ���� ���������� �������� �����
                                                               //
                              FW_DONTCARE,                     // ������� ������
                                                               //
                              TRUE,                           // ��������� ��������� ���������� ������
                                                               //
                              TRUE,                           // ��������� ��������� �������������
                                                               //
                              FALSE,                           // ��������� ��������� ������������
                                                               //
                              ANSI_CHARSET,                    // ������������� ������ ��������
                                                               //
                              OUT_TT_PRECIS,                   // �������� ������
                                                               //
                              CLIP_DEFAULT_PRECIS,             // �������� ���������
                                                               //
                              DEFAULT_QUALITY,                 // �������� ������
                                                               //
                              DEFAULT_PITCH | FF_DONTCARE,     // ��� ����� ��������� ������ � ���������
                                                               //
                              TEXT("Consolas")                 // ��� ��������� ������
                              );
                        SendMessage(button2, WM_SETFONT, (WPARAM)hFont, TRUE);
                        MessageBox(hw, bt2_message, "Special message", MB_OKCANCEL);
                    }
                    break;
                case ID_FILE_EXIT:  /* ������� ���� Exit */
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
                default: /* ��� ��������� ������� */
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
        /* ������������ ������ ����, ��������� ����� ����������� */
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hw,msg,wp,lp);
}

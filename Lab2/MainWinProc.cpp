#include <windows.h>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "defines.h"
#include "person.h"
#include "button_characteristics.h"

pers man[number_of_persons];

/* ��������� ��������� ��������� ��� �������� ���� */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    static HWND button1, button2, button3;
    static bt bt1(25, 30, 100, 90);
    static bt bt2(135, 30, 100, 90);
    static bt bt3(20, 280, 0, 0);
    static bt lb1(20, 140, 0, 0);
    static HWND hWndList;
    static HWND hWndHScrollBar, hWndVScrollBar;
    const int ScrollBarWidth  = 15;
    const int ScrollBarHeight = 15;
    RECT Rect;

    static HDC hdc;
    string description[] = {{"The combinations of hot keywords:"},
                            {"Shift + O - show the database"},
                            {"Shift + P - close the database"},
                            {"Shift + S - see description"},
                            {"Shift + V - close description"},
                            {"TAB + S - sort info in database in ascending order"},
                            {"Shift + X - close whole Application"}};

    ifstream input;

    switch (msg)
    {
    case WM_CREATE:
        GetClientRect(hw, &Rect);
        hWndVScrollBar = CreateWindowEx(
                                        0,                                                  // ���������� ����� ����
                                                                                            //
                                        "SCROLLBAR",                                        // ��������� �� ������������������ ��� ������
                                                                                            //
                                        NULL,                                               // ��������� �� ��� ����
                                                                                            //
                                        WS_VISIBLE | WS_CHILD | SBS_VERT,                   // ����� ����
                                                                                            //
                                        Rect.right - ScrollBarWidth,                        // �������������� ������� ����
                                                                                            //
                                        0,                                                  // ������������ ������� ����
                                                                                            //
                                        ScrollBarWidth,                                     // ������ ����
                                                                                            //
                                        Rect.bottom - ScrollBarHeight,                      // ������ ����
                                                                                            //
                                        hw,                                                 // ���������� ������������� ��� ���� ���������
                                                                                            //
                                        (HMENU)ID_VSCROLLBAR,                               // ���������� ���� ��� ID ��������� ����
                                                                                            //
                                        (HINSTANCE)GetWindowLong(hw, GWL_HINSTANCE),        // ���������� ���������� ���������� ���������
                                                                                            //
                                        NULL                                                // ��������� �� ������ �������� ����
                                        );
        if (!hWndVScrollBar)
        MessageBox(NULL, "Vertical Scroll Bar Failed.", "Error", MB_OK | MB_ICONERROR);
        hWndHScrollBar = CreateWindowEx(
                                        0,                                               // ���������� ����� ����
                                                                                         //
                                        "SCROLLBAR",                                     // ��������� �� ������������������ ��� ������
                                                                                         //
                                        NULL,                                            // ��������� �� ��� ����
                                                                                         //
                                        WS_VISIBLE | WS_CHILD | SBS_HORZ,                // ����� ����
                                                                                         //
                                        0,                                               // �������������� ������� ����
                                                                                         //
                                        Rect.bottom - ScrollBarHeight,                   // ������������ ������� ����
                                                                                         //
                                        Rect.right - ScrollBarWidth,                     // ������ ����
                                                                                         //
                                        ScrollBarHeight,                                 // ������ ����
                                                                                         //
                                        hw,                                              // ���������� ������������� ��� ���� ���������
                                                                                         //
                                        (HMENU)ID_HSCROLLBAR,                            // ���������� ���� ��� ID ��������� ����
                                                                                         //
                                        (HINSTANCE)GetWindowLong(hw, GWL_HINSTANCE),     // ���������� ���������� ���������� ���������
                                                                                         //
                                        NULL                                             // ��������� �� ������ �������� ����
                                        );
        if (!hWndHScrollBar)
        MessageBox(NULL, "Horizontal Scroll Bar Failed.", "Error", MB_OK | MB_ICONERROR);
        SetScrollRange(hWndVScrollBar, SB_CTL, 0, 100, TRUE);
        SetScrollRange(hWndHScrollBar, SB_CTL, 0, 100, TRUE);


        /* ��� �������� ���� �������� � ���� �������� */
        button1 = CreateWindow(
                     "button",                           // ��������� �� ������������������ ��� ������
                                                         //
                     "Database",                         // ��������� �� ��� ����
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
                     "Description",                       // ��������� �� ��� ����
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
         hWndList = CreateWindowEx(
                                  WS_EX_CLIENTEDGE,                                        // ���������� ����� ����
                                                                                           //
                                  TEXT("listbox"),                                         // ��������� �� ������������������ ��� ������
                                                                                           //
                                  "Database",                                              // ��������� �� ��� ����
                                                                                           //
                                  WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL,     // ����� ����
                                                                                           //
                                  lb1.horizontal_position,                                 // �������������� ������� ����
                                                                                           //
                                  lb1.vertical_position,                                   // ������������ ������� ����
                                                                                           //
                                  lb1.width,                                               // ������ ����
                                                                                           //
                                  lb1.height,                                              // ������ ����
                                                                                           //
                                  hw,                                                      // ���������� ������������� ��� ���� ���������
                                                                                           //
                                  (HMENU)105,                                              // ���������� ���� ��� ID ��������� ����
                                                                                           //
                                  NULL,                                                    // ���������� ���������� ���������� ���������
                                                                                           //
                                  NULL                                                     // ��������� �� ������ �������� ����
                                  );
            button3 = CreateWindowEx(
                                     NULL,                                      // ���������� ����� ����
                                                                                //
                                     TEXT("button"),                            // ��������� �� ������������������ ��� ������
                                                                                //
                                     TEXT("Sort"),                              // ��������� �� ��� ����
                                                                                //
                                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,         // ����� ����
                                                                                //
                                     bt3.horizontal_position,                   // �������������� ������� ����
                                                                                //
                                     bt3.vertical_position,                     // ������������ ������� ����
                                                                                //
                                     bt3.width,                                 // ������ ����
                                                                                //
                                     bt3.height,                                // ������ ����
                                                                                //
                                     hw,                                        // ���������� ������������� ��� ���� ���������
                                                                                //
                                     (HMENU)ID_BUTTON3,                         // ���������� ���� ��� ID ��������� ����
                                                                                //
                                     NULL,                                      // ���������� ���������� ���������� ���������
                                                                                //
                                     NULL                                       // ��������� �� ������ �������� ����
                                    );
            input.close();
        return 0;
    case WM_HSCROLL:
        {
            switch ((int)LOWORD(wp))
            {
                case SB_LINEUP:
                    SetScrollPos((HWND)lp, SB_CTL, 0, TRUE);
                    break;
                case SB_LINEDOWN:
                    SetScrollPos((HWND)lp, SB_CTL, 100, TRUE);
                    break;
            }
            return 0;
        }
        break;
    case WM_VSCROLL:
        {
            switch ((int)LOWORD(wp))
            {
                case SB_LINEUP:
                    SetScrollPos((HWND)lp, SB_CTL, 0, TRUE);
                    break;
                case SB_LINEDOWN:
                    SetScrollPos((HWND)lp, SB_CTL, 100, TRUE);
                    break;
            }
            return 0;
        }
        break;
    case WM_COMMAND:
        if (HIWORD(wp)==0)
        {
            char buf[256];
            switch (LOWORD(wp))
            {
                case ID_BUTTON1:
                    MessageBox(hw, "Shift + O", "Special message", MB_OK);
                    bt1 = bt(25, 30, 0, 0);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case ID_BUTTON2:
                    {
                        char bt2_message[] = "The description - Shift + C ;)";
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
                        bt2 = bt(135, 30, 0, 0);
                        MoveWindow(button2, bt2.horizontal_position, bt2.vertical_position, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_BUTTON3:
                    bt3 = bt(20, 280, 0, 0);
                    MoveWindow(button3, bt3.horizontal_position, bt3.horizontal_position, bt3.width, bt3.height, TRUE);
                    for(int i = 0; i < number_of_persons - 1; i++)
                    for(int j = 0; j < number_of_persons - 1 - i; j++)
                    {
                        if (man[j] > man[j + 1])
                        {
                            pers tmp = man[j];
                            man[j] = man[j + 1];
                            man[j + 1] = tmp;
                        }
                    }
                    SendMessage(hWndList, LB_RESETCONTENT, 0, 0);
                    lb1 = bt(20, 140, 300, 120);
                    MoveWindow(hWndList, lb1.horizontal_position, lb1.vertical_position, lb1.width, lb1.height, TRUE);
                    for(int i = 0; i < number_of_persons; i++)
                    {
                        input >> man[i];
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].info().c_str());
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].address.c_str());
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)"----------------------------------------------------------------");
                    }
                    break;
                case ID_FILE_OPEN_DATABASE:
                    input.open("input.txt",ios::in);
                    for(int i = 0; i < number_of_persons; i++)
                    {
                        MoveWindow(hWndList, 20, 140, 300, 120, TRUE);
                        input >> man[i];
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].info().c_str());
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].address.c_str());
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)"----------------------------------------------------------------");
                    }
                    input.close();
                    bt3 = bt(20, 280, 50, 40);
                    MoveWindow(button3, bt3.horizontal_position, bt3.vertical_position, bt3.width, bt3.height, TRUE);
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
                        int yClient = rect.bottom - rect.top - 35;
                        bt2 = bt(135, 30, 100, 90);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_EDIT_RESIZE_BUTTON2_BIGGER:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 35;
                        bt2 = bt(135, 30, 120, 105);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_EDIT_RESIZE_BUTTON2_SMALLER:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 35;
                        bt2 = bt(135, 30, 80, 70);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case ID_EDIT_RESIZE_WINDOW_780X430:
                    MoveWindow(hw, 0, 0, 780, 430, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_820X460:
                    MoveWindow(hw, 0, 0, 820, 460, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_900X512:
                    MoveWindow(hw, 0, 0, 900, 512, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_950X620:
                    MoveWindow(hw, 0, 0, 950, 620, TRUE);
                    break;
                case ID_EDIT_RESIZE_WINDOW_1366X768:
                    MoveWindow(hw, 0, 0, 1366, 768, TRUE);
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
    case WM_CHAR:
        {
            int iKey = LOWORD(wp);
            int shiftValue = GetKeyState(VK_SHIFT);
            if(shiftValue)
            {
                if (iKey == (int)('o') || iKey == (int)('O'))
                {
                    bt1 = bt(25, 30, 100, 90);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    SendMessage(hWndList, LB_RESETCONTENT, 0, 0);
                    input.open("input.txt",ios::in);
                    for(int i = 0; i < number_of_persons; i++)
                    {
                        MoveWindow(hWndList, 20, 140, 300, 120, TRUE);
                        input >> man[i];
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].info().c_str());
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].address.c_str());
                        SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)"----------------------------------------------------------------");
                    }
                    bt3 = bt(20, 280, 50, 40);
                    MoveWindow(button3, bt3.horizontal_position, bt3.vertical_position, bt3.width, bt3.height, TRUE);
                    input.close();
                    return 0;
                }
                else if (iKey == (int)('p') || iKey == (int)('P'))
                {
                    lb1 = bt(20, 140, 0, 0);
                    MoveWindow(hWndList, lb1.horizontal_position, lb1.vertical_position, lb1.width, lb1.height, TRUE);
                    bt3 = bt(20, 280, 0, 0);
                    MoveWindow(button3, bt3.horizontal_position, bt3.vertical_position, bt3.width, bt3.height, TRUE);
                    return 0;
                }
                else if (iKey == (int)('c') || iKey == (int)('C'))
                {
                    hdc = GetWindowDC(hw);
                    mt19937 rnd(time(NULL));
                    SetTextColor (hdc, RGB(0, 127, 255));
                    SetBkMode (hdc, OPAQUE);
                    for(int i = 0; i < 7; i++)
                    {
                        int R = rnd(), G = rnd() % 90, B = rnd() % 150;
                        SetBkColor(hdc, RGB(R, G, B));
                        TextOut (hdc, 320, 60 + i * 15, description[i].c_str(), description[i].size());
                    }
                    ReleaseDC (hw, hdc);
                    return 0;
                }
                else if (iKey == (int)('v') || iKey == (int)('V'))
                {
                    InvalidateRect(hw, NULL, TRUE);
                    RECT rect = {0};
                    GetWindowRect(hw, &rect);
                    int xClient = rect.right - rect.left;
                    int yClient = rect.bottom - rect.top - 35;
                    bt2 = bt(135, 30, 100, 90);
                    MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    return 0;
                }
                else if (iKey == (int)('x') || iKey == (int)('X'))
                {
                    /* ������������ ������ ����, ��������� ����� ����������� */
                    PostQuitMessage(0);
                    return 0;
                }
            }
            int tabValue = GetKeyState(VK_TAB);
            if (tabValue && bt3.width && (iKey == (int)('s') || iKey == (int)('S')))
            {
                bt3 = bt(20, 280, 0, 0);
                MoveWindow(button3, bt3.horizontal_position, bt3.horizontal_position, bt3.width, bt3.height, TRUE);
                for(int i = 0; i < number_of_persons - 1; i++)
                for(int j = 0; j < number_of_persons - 1 - i; j++)
                {
                    if (man[j] > man[j + 1])
                    {
                        pers tmp = man[j];
                        man[j] = man[j + 1];
                        man[j + 1] = tmp;
                    }
                }
                SendMessage(hWndList, LB_RESETCONTENT, 0, 0);
                lb1 = bt(20, 140, 300, 120);
                MoveWindow(hWndList, lb1.horizontal_position, lb1.vertical_position, lb1.width, lb1.height, TRUE);
                for(int i = 0; i < number_of_persons; i++)
                {
                    input >> man[i];
                    SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].info().c_str());
                    SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)man[i].address.c_str());
                    SendMessage(hWndList, LB_ADDSTRING, 0, (LPARAM)"----------------------------------------------------------------");
                }
                return 0;
            }
        }
        return 0;
    case WM_SIZE:
        {
            int xClient = LOWORD(lp);
            int yClient = HIWORD(lp);
            MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
            MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
            MoveWindow(hWndVScrollBar, xClient - ScrollBarWidth, 0, ScrollBarWidth, yClient - ScrollBarHeight, TRUE);
            MoveWindow(hWndHScrollBar, 0, yClient - ScrollBarHeight, xClient - ScrollBarWidth, ScrollBarHeight, TRUE);
        }
        return 0;
    case WM_DESTROY:
        /* ������������ ������ ����, ��������� ����� ����������� */
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hw,msg,wp,lp);
}

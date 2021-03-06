#include <windows.h>
#include <time.h>
#include "defines.h"
#include "button_characteristics.h"

void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}

LRESULT CALLBACK MainWinProc(
                             HWND,    // ���������� ������
                                      //
                             UINT,    // ���������, ���������� ��
                                      //
                             WPARAM,  // ��������� ���������, ��� ������������ ���������
                                      //
                             LPARAM   // ��������� ���������, ��� ������������ ���������
                             );

int WINAPI WinMain(
                   HINSTANCE hInst, // ���������� ��� ������� ���������� ���������
                                    //
                   HINSTANCE hpi,   // � Win32 �� ������������ (������ NULL)
                                    //
                   LPSTR cmdline,   // ��������� ������
                                    //
                   int ss           // ��� ��������� �������� ����
                   )
{
    /* ������� � ������������ ����� �������� ���� */
    WNDCLASS wc;                                // ���������, ������� �������� �������� ������ ����
                                                //
    wc.style=0;                                 // ������������� �����(�) ������. ���� ���� ���������
                                                // ����� ���� ����� ����������� ������ ������.
                                                //
    wc.lpfnWndProc=MainWinProc;                 // ��������� �� ������� ���������. �� ������ ������������
                                                // ������� CallWindowProc, ����� ������� ������� ���������.
                                                //
    wc.cbClsExtra=wc.cbWndExtra=0;              // ������������� ����� �������������� ����, �������
                                                // ����������� ����� �� ���������� ������ ����.
                                                // ������� �������������� ��� ����� ������.
                                                //
    wc.hInstance=hInst;                         // ���������� ����������, ������� �������� �������
                                                // ��������� ��� ������.
                                                //
    wc.hIcon=LoadIcon(hInst,"Icon");;           // ���������� ������ ������. ���� ���� ���������
                                                // ������ ���� ������������ ������� ������.
                                                // ���� ���� ���� ��������� - ����� (NULL), �������
                                                // ������������� �������� �� ��������� ������.
                                                //
    wc.hCursor=NULL;                            // ���������� ������� ������. ���� ���� ��������� ������ ����
                                                // ������������ ������� �������. ���� ���� ���� ��������� - ����� (NULL),
                                                // ���������� ������ ���� ������������� ����� ������� ������ ���,
                                                // ����� ���� ������������ � ���� ���������� ���������.
                                                //
    wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);  // ���������� ����� ���� ������. ���� ���� ��������� ����� ����
                                                // ������������ ���������� �����, ������� ������������, ����� �������
                                                // ������ ����, ��� ��� ����� ���� ����� �����. ��� ����� ������ ����
                                                // ����� �� ���� ������������� ����������� ��������� ������
                                                // (�������� 1 ������ ����������� � ���������� �����).
                                                // ���� ������ ��� �����, �� ������ ������������� ��� � ���� �� ����� HBRUSH.
                                                //
    wc.lpszMenuName="Menu";                     // ��������� �� ���������� ������ � �������� ����� ������ ('\0') (����-������������),
                                                // ������� ������������� ��� ������� ���� ������, ������� ��� ��� ������������ �
                                                // ����� �������. ���� �� ����������� ����� �����, ����� ���������������� ����,
                                                // ����������� ������ MAKEINTRESOURCE. ���� ���� ���� ��������� - ����� (NULL),
                                                // ����, ������������� ����� ������, �� ����� �������� ��������� �� ��������� ����.
                                                //
    wc.lpszClassName="MainWnd Class";           // ��������� �� ���������� ������ � ����� � ����� ���  ����. ���� ���� �������� - ����,
                                                // ��� ������ ���� ���� ������, ��������� ���������� ������� ������� RegisterClass ���
                                                // RegisterClassEx. ���� ������ ���������� � ������� ����� lpszClassName;
                                                // ������� ����� ������ ���� ����.

 if (!RegisterClass(&wc)) return FALSE;

 /* ������� ������� ���� � ���������� ��� */
    HWND hMainWnd=CreateWindow(
                                "MainWnd Class",                // ��������� �� ������������������ ��� ������
                                                                //
                                "SUDOKU - Ganuscheak_Vlad<c>",  // ��������� �� ��� ����
                                                                //
                                WS_OVERLAPPEDWINDOW,            // ����� ����
                                                                //
                                CW_USEDEFAULT,                  // �������������� ������� ����
                                                                //
                                CW_USEDEFAULT,                  // ������������ ������� ����
                                                                //
                                MIN_WINDOW_SIZE_OX,             // ������ ����
                                                                //
                                MIN_WINDOW_SIZE_OY,             // ������ ����
                                                                //
                                NULL,                           // ���������� ������������� ��� ���� ���������
                                                                //
                                NULL,                           // ���������� ���� ��� ID ��������� ����
                                                                //
                                hInst,                          // ���������� ���������� ����������
                                                                //
                                NULL                            // ��������� �� ������ �������� ����
                                );

    Stealth();

    if (!hMainWnd) return FALSE;
    ShowWindow(hMainWnd,ss);
    UpdateWindow(hMainWnd);

    MSG msg; /* ���� ��������� ������� */
    while (GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

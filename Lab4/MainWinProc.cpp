#include <windows.h>
#include <iostream>
#include <vector>
#include <string.h>

#include <random>
#include <ctime>
#include "defines.h"
#include "drawing.h"
#include "template_functions.h"

/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp)
{
    static HDC hdc;

    PAINTSTRUCT ps;

    static bool ignoreWindowSize = false;

    static std::vector<figure*> staticFigures;
    static std::vector<circle*> dynamicFigures;

    static RECT Rect;

    static square sq1, sq2;
    static rectangle bareer1, bareer2, bareer3, bareer4;
    static ellipse el1;
    static circle cir1, cir2, cir3, cir4, cir5, cir6, cir7, cir8, cir9, cir10;

    switch (msg)
    {
    case WM_CREATE: // создание окна
    {
        GetClientRect(hw, &Rect);
        std::mt19937 rnd(time(NULL));

        sq1.set_startX(560);
        sq1.set_startY(90);
        sq1.set_endX(480);
        sq1.set_endY(170);
        sq1.set_RGB(130, 190, 130);
        sq1.update();
        staticFigures.push_back(&sq1);

        sq2.set_startX(690);
        sq2.set_startY(430);
        sq2.set_endX(820);
        sq2.set_endY(320);
        sq2.set_RGB(200, 17, 169);
        sq2.update();
        staticFigures.push_back(&sq2);

        el1.set_startX(70);
        el1.set_startY(220);
        el1.set_endX(130);
        el1.set_endY(370);
        el1.set_RGB(130, 231, 97);
        staticFigures.push_back(&el1);

        bareer1.set_startX(0);
        bareer1.set_startY(0);
        bareer1.set_endX(Rect.right);
        bareer1.set_endY(10);
        bareer1.set_RGB(0, 0, 0);
        staticFigures.push_back(&bareer1);

        bareer2.set_startX(Rect.right - 10);
        bareer2.set_startY(0);
        bareer2.set_endX(Rect.right);
        bareer2.set_endY(Rect.bottom);
        bareer2.set_RGB(0, 0, 0);
        staticFigures.push_back(&bareer2);

        bareer3.set_startX(0);
        bareer3.set_startY(0);
        bareer3.set_endX(10);
        bareer3.set_endY(Rect.bottom);
        bareer3.set_RGB(0, 0, 0);
        staticFigures.push_back(&bareer3);

        bareer4.set_startX(0);
        bareer4.set_startY(Rect.bottom - 10);
        bareer4.set_endX(Rect.right);
        bareer4.set_endY(Rect.bottom);
        bareer4.set_RGB(0, 0, 0);
        staticFigures.push_back(&bareer4);

        cir1.set_startX(rnd() % 100 + 20);
        cir1.set_startY(rnd() % 100 + 20);
        cir1.set_endX(cir1.get_startX() + rnd() % 50 + 35);
        cir1.set_endY(cir1.get_startY() + rnd() % 50 + 35);
        cir1.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir1.set_speed(30);
        cir1.set_angle(rnd() % 360);
        cir1.update();
        cir1.define_radius();
        dynamicFigures.push_back(&cir1);

        cir2.set_startX(rnd() % 100 + 20);
        cir2.set_startY(rnd() % 100 + 20);
        cir2.set_endX(cir2.get_startX() + rnd() % 50 + 35);
        cir2.set_endY(cir2.get_startY() + rnd() % 50 + 35);
        cir2.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir2.set_speed(30);
        cir2.set_angle(rnd() % 360);
        cir2.update();
        cir2.define_radius();
        dynamicFigures.push_back(&cir2);

        cir3.set_startX(rnd() % 100 + 20);
        cir3.set_startY(rnd() % 100 + 20);
        cir3.set_endX(cir3.get_startX() + rnd() % 50 + 35);
        cir3.set_endY(cir3.get_startY() + rnd() % 50 + 35);
        cir3.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir3.set_speed(30);
        cir3.set_angle(rnd() % 360);
        cir3.update();
        cir3.define_radius();
        dynamicFigures.push_back(&cir3);

        cir4.set_startX(rnd() % 100 + 20);
        cir4.set_startY(rnd() % 100 + 20);
        cir4.set_endX(cir4.get_startX() + rnd() % 50 + 35);
        cir4.set_endY(cir4.get_startY() + rnd() % 50 + 35);
        cir4.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir4.set_speed(30);
        cir4.set_angle(rnd() % 360);
        cir4.update();
        cir4.define_radius();
        dynamicFigures.push_back(&cir4);

        cir5.set_startX(rnd() % 100 + 20);
        cir5.set_startY(rnd() % 100 + 20);
        cir5.set_endX(cir5.get_startX() + rnd() % 50 + 35);
        cir5.set_endY(cir5.get_startY() + rnd() % 50 + 35);
        cir5.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir5.set_speed(30);
        cir5.set_angle(rnd() % 360);
        cir5.update();
        cir5.define_radius();
        dynamicFigures.push_back(&cir5);

        cir6.set_startX(rnd() % 100 + 20);
        cir6.set_startY(rnd() % 100 + 20);
        cir6.set_endX(cir4.get_startX() + rnd() % 50 + 35);
        cir6.set_endY(cir4.get_startY() + rnd() % 50 + 35);
        cir6.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir6.set_speed(30);
        cir6.set_angle(rnd() % 360);
        cir6.update();
        cir6.define_radius();
        dynamicFigures.push_back(&cir6);

        cir7.set_startX(rnd() % 100 + 20);
        cir7.set_startY(rnd() % 100 + 20);
        cir7.set_endX(cir7.get_startX() + rnd() % 50 + 35);
        cir7.set_endY(cir7.get_startY() + rnd() % 50 + 35);
        cir7.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir7.set_speed(30);
        cir7.set_angle(rnd() % 360);
        cir7.update();
        cir7.define_radius();
        dynamicFigures.push_back(&cir7);

        cir8.set_startX(rnd() % 100 + 20);
        cir8.set_startY(rnd() % 100 + 20);
        cir8.set_endX(cir4.get_startX() + rnd() % 50 + 35);
        cir8.set_endY(cir4.get_startY() + rnd() % 50 + 35);
        cir8.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir8.set_speed(30);
        cir8.set_angle(rnd() % 360);
        cir8.update();
        cir8.define_radius();
        dynamicFigures.push_back(&cir8);

        cir9.set_startX(rnd() % 100 + 20);
        cir9.set_startY(rnd() % 100 + 20);
        cir9.set_endX(cir4.get_startX() + rnd() % 50 + 35);
        cir9.set_endY(cir4.get_startY() + rnd() % 50 + 35);
        cir9.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir9.set_speed(30);
        cir9.set_angle(rnd() % 360);
        cir9.update();
        cir9.define_radius();
        dynamicFigures.push_back(&cir9);

        cir10.set_startX(rnd() % 100 + 20);
        cir10.set_startY(rnd() % 100 + 20);
        cir10.set_endX(cir4.get_startX() + rnd() % 50 + 35);
        cir10.set_endY(cir4.get_startY() + rnd() % 50 + 35);
        cir10.set_RGB(rnd() % 256, rnd() % 256, rnd() % 256);
        cir10.set_speed(30);
        cir10.set_angle(rnd() % 360);
        cir10.update();
        cir10.define_radius();
        dynamicFigures.push_back(&cir10);

        SetTimer(hw, ID_TIMER1, 300, NULL);
    }
    return 0;
    case WM_COMMAND:
        switch(HIWORD(wp))
        {
            case 0:
                {
                char buf[256];
                switch (LOWORD(wp))
                {
                    default: /* все остальные команды */
                        wsprintf(buf,"Command code: %d",LOWORD(wp));
                        MessageBox(hw,buf,"MessageBox",MB_OK|MB_ICONINFORMATION);
                }
            }
            break;
            case EN_UPDATE:
            {

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
    case WM_TIMER:
    {
        switch (wp) //wParam - номер таймера (nIDEvent)
        {
            case ID_TIMER1:
                SetTimer(hw, ID_TIMER1, 300, NULL);
                for(int i = 0; i < dynamicFigures.size(); i++)
                if (dynamicFigures[i]->get_name() == "circle")
                {
                    dynamicFigures[i]->calculate();
                    HBRUSH hbr=CreateSolidBrush(RGB(dynamicFigures[i]->get_RGB_RED(), dynamicFigures[i]->get_RGB_GREEN(), dynamicFigures[i]->get_RGB_BLUE()));
                    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);

                    drawCircle(hdc, dynamicFigures[i]);

                    SelectObject(hdc,hOld);
                    DeleteObject(hbr);
                }
                for(int i = 0; i < dynamicFigures.size(); i++)
                {
                    for(int j = 0; j < staticFigures.size(); j++)
                    {
                        if (In(dynamicFigures[i]->get_centerX(),
                               dynamicFigures[i]->get_centerY(),
                               dynamicFigures[i]->get_radius(),
                               minimum(staticFigures[j]->get_startX(), staticFigures[j]->get_endX()),
                               minimum(staticFigures[j]->get_startY(), staticFigures[j]->get_endY()),
                               maximum(staticFigures[j]->get_startX(), staticFigures[j]->get_endX()),
                               maximum(staticFigures[j]->get_startY(), staticFigures[j]->get_endY())))
                        {
                            if (dynamicFigures[i]->intersected_ind != j)
                            {
                                int angle = dynamicFigures[i]->get_angle();
                                if (vertical(dynamicFigures[i]->get_centerX(),
                                             dynamicFigures[i]->get_centerY(),
                                             staticFigures[j]->get_startX(),
                                             staticFigures[j]->get_startY(),
                                             staticFigures[j]->get_endX(),
                                             staticFigures[j]->get_endY()))
                                    {
                                        if (angle % 90 == 0)
                                        {
                                            dynamicFigures[i]->set_angle((angle + 180) % 360);
                                        }
                                        else if ((angle <= 90) || (angle >= 180 && angle <= 270))
                                        {
                                            dynamicFigures[i]->set_angle((angle + 90) % 360);
                                        }
                                        else
                                        {
                                            dynamicFigures[i]->set_angle(angle - 90);
                                        }
                                    }
                                    else
                                    {
                                        if (angle % 90 == 0)
                                        {
                                            dynamicFigures[i]->set_angle((angle + 180) % 360);
                                        }
                                        else if ((angle <= 90) || (angle >= 180 && angle <= 270))
                                        {
                                            dynamicFigures[i]->set_angle((angle + 270) % 360);
                                        }
                                        else
                                        {
                                            dynamicFigures[i]->set_angle((angle + 90) % 360);
                                        }
                                    }
                                dynamicFigures[i]->intersected_ind = j;
                                break;
                            }
                        }
                    }
                }
                //system("pause");
                InvalidateRect(hw, NULL, TRUE);
                SetFocus(hw);
                break;
        }
    }
    return 0;
    case WM_SIZE:
    {
        hdc = BeginPaint(hw, &ps);
        for(int i = 0; i < staticFigures.size(); i++)
        if (staticFigures[i]->get_name() == "square")
        {
            drawSquare(hdc, staticFigures[i]);

            RECT r;
            r.left = minimum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.right = maximum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.top = minimum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());
            r.bottom = maximum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());

            FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(staticFigures[i]->get_RGB_RED(), staticFigures[i]->get_RGB_GREEN(), staticFigures[i]->get_RGB_BLUE())));
        }
        else if (staticFigures[i]->get_name() == "rectangle")
        {
            drawRectangle(hdc, staticFigures[i]);

            RECT r;
            r.left = minimum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.right = maximum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.top = minimum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());
            r.bottom = maximum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());

            FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(staticFigures[i]->get_RGB_RED(), staticFigures[i]->get_RGB_GREEN(), staticFigures[i]->get_RGB_BLUE())));
        }
        else if (staticFigures[i]->get_name() == "ellipse")
        {
            HBRUSH hbr=CreateSolidBrush(RGB(staticFigures[i]->get_RGB_RED(), staticFigures[i]->get_RGB_GREEN(), staticFigures[i]->get_RGB_BLUE()));
            HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);

            drawEllipse(hdc, staticFigures[i]);

            SelectObject(hdc,hOld);
            DeleteObject(hbr);
        }

        for(int i = 0; i < dynamicFigures.size(); i++)
        if (dynamicFigures[i]->get_name() == "circle")
        {
            HBRUSH hbr=CreateSolidBrush(RGB(dynamicFigures[i]->get_RGB_RED(), dynamicFigures[i]->get_RGB_GREEN(), dynamicFigures[i]->get_RGB_BLUE()));
            HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);

            drawCircle(hdc, dynamicFigures[i]);

            SelectObject(hdc,hOld);
            DeleteObject(hbr);
        }
    }
    return 0;
    case WM_PAINT:
    {
        hdc = BeginPaint(hw, &ps);
        for(int i = 0; i < staticFigures.size(); i++)
        if (staticFigures[i]->get_name() == "square")
        {
            drawSquare(hdc, staticFigures[i]);

            RECT r;
            r.left = minimum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.right = maximum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.top = minimum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());
            r.bottom = maximum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());

            FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(staticFigures[i]->get_RGB_RED(), staticFigures[i]->get_RGB_GREEN(), staticFigures[i]->get_RGB_BLUE())));
        }
        else if (staticFigures[i]->get_name() == "rectangle")
        {
            drawRectangle(hdc, staticFigures[i]);

            RECT r;
            r.left = minimum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.right = maximum(staticFigures[i]->get_startX(), staticFigures[i]->get_endX());
            r.top = minimum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());
            r.bottom = maximum(staticFigures[i]->get_startY(), staticFigures[i]->get_endY());

            FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(staticFigures[i]->get_RGB_RED(), staticFigures[i]->get_RGB_GREEN(), staticFigures[i]->get_RGB_BLUE())));
        }
        else if (staticFigures[i]->get_name() == "ellipse")
        {
            HBRUSH hbr=CreateSolidBrush(RGB(staticFigures[i]->get_RGB_RED(), staticFigures[i]->get_RGB_GREEN(), staticFigures[i]->get_RGB_BLUE()));
            HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);

            drawEllipse(hdc, staticFigures[i]);

            SelectObject(hdc,hOld);
            DeleteObject(hbr);
        }

        for(int i = 0; i < dynamicFigures.size(); i++)
        if (dynamicFigures[i]->get_name() == "circle")
        {
            HBRUSH hbr=CreateSolidBrush(RGB(dynamicFigures[i]->get_RGB_RED(), dynamicFigures[i]->get_RGB_GREEN(), dynamicFigures[i]->get_RGB_BLUE()));
            HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);

            drawCircle(hdc, dynamicFigures[i]);

            SelectObject(hdc,hOld);
            DeleteObject(hbr);
        }
        ValidateRect(hw, NULL);
        EndPaint(hw, &ps);
    }
    return 0;
    case WM_DESTROY:
    {
        /* пользователь закрыл окно, программа может завершаться */
        KillTimer(hw, ID_TIMER1);
        PostQuitMessage(0);
    }
    return 0;
    default:
        return DefWindowProc(hw,msg,wp,lp);
    }
    return DefWindowProc(hw,msg,wp,lp);
}

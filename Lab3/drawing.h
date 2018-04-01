#ifndef DRAWING_H_INCLUDED
#define DRAWING_H_INCLUDED

typedef struct Figure
{
    char* name;
    int pos_x1;
    int pos_y1;
    int pos_x2;
    int pos_y2;

    int R = 255;
    int G = 255;
    int B = 255;

    RECT r;

    Figure(char* new_name, int x1, int y1, int x2, int y2)
    :  pos_x1(x1)
    ,  pos_y1(y1)
    ,  pos_x2(x2)
    ,  pos_y2(y2)
    {
        name = new char[strlen(new_name) + 1];
        strcpy(name, new_name);

        r.left = minimum(pos_x1, pos_x2) + 1;
        r.top = minimum(pos_y1, pos_y2) + 1;
        r.right = maximum(pos_x1, pos_x2) - 1;
        r.bottom = maximum(pos_y1, pos_y2) - 1;
    }
}fig;

typedef struct BezierSD
{
    int n;
    POINT* arr;
    int index;
    BezierSD(int new_n, POINT* new_arr, int new_index)
    :  n(new_n)
    ,  index(new_index)
    {
        arr = new POINT[new_n];
        for(int i = 0; i < n; i++)
        {
            arr[i].x = new_arr[i].x;
            arr[i].y = new_arr[i].y;
        }
    }
}BezierSD;

bool prevSetted = false;
int prevX;
int prevY;

int nBezierPoints = 0;
POINT *BezierPointsArray;
bool drawBezier = false;

int R = 255;
int G = 255;
int B = 255;

namespace drawPrimitives
{

    namespace figureRectangle
    {
        void drawRectangle(HDC hdc, fig figura)
        {
            Rectangle(hdc, figura.pos_x1, figura.pos_y1, figura.pos_x2, figura.pos_y2);
        }

        void SetRectangle(HDC hdc, int *StartX, int *StartY, int *EndX, int *EndY, LPARAM lp)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            {   // до нажатия левой кнопки мыши:
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *EndX, *StartY);
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *StartX, *EndY);

                MoveToEx(hdc, *EndX, *StartY, NULL);
                LineTo(hdc, *EndX, *EndY);
                MoveToEx(hdc, *StartX, *EndY, NULL);
                LineTo(hdc, *EndX, *EndY);
            }

            *EndX = LOWORD(lp);
            *EndY = HIWORD(lp);

            {   // после нажатия левой кнопки мыши:
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *EndX, *StartY);
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *StartX, *EndY);

                MoveToEx(hdc, *EndX, *StartY, NULL);
                LineTo(hdc, *EndX, *EndY);
                MoveToEx(hdc, *StartX, *EndY, NULL);
                LineTo(hdc, *EndX, *EndY);
            }
        }
    }


    namespace figureSquare
    {
        void drawSquare(HDC hdc, fig figura)
        {
            Rectangle(hdc, figura.pos_x1, figura.pos_y1, figura.pos_x2, figura.pos_y2);
        }

        void SetSquare(HDC hdc, int *StartX, int *StartY, int *EndX, int *EndY, LPARAM lp)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            int minVal = minimum(absVal(*StartX - *EndX), absVal(*StartY - *EndY));
            int sgX = ((*EndX < *StartX) ? -1 : 1);
            int sgY = ((*EndY < *StartY) ? -1 : 1);

            *EndX = *StartX + sgX * minVal;
            *EndY = *StartY + sgY * minVal;


            {   // до нажатия левой кнопки мыши:
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *EndX, *StartY);
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *StartX, *EndY);

                MoveToEx(hdc, *EndX, *StartY, NULL);
                LineTo(hdc, *EndX, *EndY);
                MoveToEx(hdc, *StartX, *EndY, NULL);
                LineTo(hdc, *EndX, *EndY);
            }

            *EndX = LOWORD(lp);
            *EndY = HIWORD(lp);

            minVal = minimum(absVal(*StartX - *EndX), absVal(*StartY - *EndY));
            sgX = ((*EndX < *StartX) ? -1 : 1);
            sgY = ((*EndY < *StartY) ? -1 : 1);

            *EndX = *StartX + sgX * minVal;
            *EndY = *StartY + sgY * minVal;

            {   // после нажатия левой кнопки мыши:
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *EndX, *StartY);
                MoveToEx(hdc, *StartX, *StartY, NULL);
                LineTo(hdc, *StartX, *EndY);

                MoveToEx(hdc, *EndX, *StartY, NULL);
                LineTo(hdc, *EndX, *EndY);
                MoveToEx(hdc, *StartX, *EndY, NULL);
                LineTo(hdc, *EndX, *EndY);
            }
        }
    }


    namespace FigureEllipse
    {
        void drawEllipse(HDC hdc, fig figura)
        {
            Ellipse(hdc, figura.pos_x1, figura.pos_y1, figura.pos_x2, figura.pos_y2);
        }

        void SetEllipse(HDC hdc, int *StartX, int *StartY, int *EndX, int *EndY, LPARAM lp)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            {   // до нажатия левой кнопки мыши:
                int middleX = (*StartX + *EndX) / 2;
                int middleY = (*StartY + *EndY) / 2;
                int width = absVal(*StartX - *EndX) / 2;
                int height = absVal(*StartY - *EndY) / 2;

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX + width, middleY);
                MoveToEx(hdc, middleX, middleY,NULL);
                LineTo(hdc, middleX - width, middleY);

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY + height);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY - height);

                FigureEllipse::drawEllipse(hdc, fig("ellipse", *StartX, *StartY, *EndX, *EndY));
            }

            *EndX = LOWORD(lp);
            *EndY = HIWORD(lp);

            {   // после нажатия левой кнопки мыши:
                int middleX = (*StartX + *EndX) / 2;
                int middleY = (*StartY + *EndY) / 2;
                int width = absVal(*StartX - *EndX) / 2;
                int height = absVal(*StartY - *EndY) / 2;

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX + width, middleY);
                MoveToEx(hdc, middleX, middleY,NULL);
                LineTo(hdc, middleX - width, middleY);

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY + height);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY - height);

                FigureEllipse::drawEllipse(hdc, fig("ellipse", *StartX, *StartY, *EndX, *EndY));
            }
        }
    }


    namespace FigureCircle
    {
        void drawCircle(HDC hdc, fig figura)
        {
            Ellipse(hdc, figura.pos_x1, figura.pos_y1, figura.pos_x2, figura.pos_y2);
        }

        void SetCircle(HDC hdc, int *StartX, int *StartY, int *EndX, int *EndY, LPARAM lp)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            {   // до нажатия левой кнопки мыши:
                int width = absVal(*StartX - *EndX);
                int height = absVal(*StartY - *EndY);
                int minVal = minimum(width, height);

                int sgX = ((*StartX > *EndX) ? -1 : 1);
                int sgY = ((*StartY > *EndY) ? -1 : 1);

                int middleX = *StartX + sgX * minVal / 2;
                int middleY = *StartY + sgY * minVal / 2;

                int Val = minVal / 2;

                *EndX = *StartX + sgX * minVal;
                *EndY = *StartY + sgY * minVal;

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY + Val * sgY);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY - Val * sgY);

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX + Val * sgX, middleY);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX - Val * sgX, middleY);

                FigureCircle::drawCircle(hdc, fig("circle", *StartX, *StartY, *EndX, *EndY));
            }

            *EndX = LOWORD(lp);
            *EndY = HIWORD(lp);

            {   // после нажатия левой кнопки мыши:
                int width = absVal(*StartX - *EndX);
                int height = absVal(*StartY - *EndY);
                int minVal = minimum(width, height);

                int sgX = ((*StartX > *EndX) ? -1 : 1);
                int sgY = ((*StartY > *EndY) ? -1 : 1);

                int middleX = *StartX + sgX * minVal / 2;
                int middleY = *StartY + sgY * minVal / 2;

                int Val = minVal / 2;

                *EndX = *StartX + sgX * minVal;
                *EndY = *StartY + sgY * minVal;

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY + Val);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX, middleY - Val);

                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX + Val, middleY);
                MoveToEx(hdc, middleX, middleY, NULL);
                LineTo(hdc, middleX - Val, middleY);

                FigureCircle::drawCircle(hdc, fig("circle", *StartX, *StartY, *EndX, *EndY));
            }
        }
    }

    namespace FigureStraightLine
    {
        void drawStraightLine(HDC hdc, fig figura)
        {
            MoveToEx(hdc, figura.pos_x1, figura.pos_y1, NULL);
            LineTo(hdc, figura.pos_x2, figura.pos_y2);
        }

        void SetStaightLine(HDC hdc, int *StartX, int *StartY, int *EndX, int *EndY, LPARAM lp)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            drawStraightLine(hdc, fig("straight_line", *StartX, *StartY, *EndX, *EndY));

            *EndX = LOWORD(lp);
            *EndY = HIWORD(lp);

            drawStraightLine(hdc, fig("straight_line", *StartX, *StartY, *EndX, *EndY));
        }
    }

    namespace FigurePolyline
    {
        void drawPolyline(HDC hdc, fig figura)
        {
            MoveToEx(hdc, figura.pos_x1, figura.pos_y1, NULL);
            LineTo(hdc, figura.pos_x2, figura.pos_y2);
        }

        void SetPolyline(HDC hdc, int *StartX, int *StartY, int *EndX, int *EndY, LPARAM lp)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            drawPolyline(hdc, fig("polyline", *StartX, *StartY, *EndX, *EndY));

            *EndX = LOWORD(lp);
            *EndY = HIWORD(lp);

            drawPolyline(hdc, fig("polyline", *StartX, *StartY, *EndX, *EndY));
        }
    }

    namespace FigureBezierCurve
    {
        void drawBezierCurve(HDC hdc, BezierSD b)
        {
            PolyBezier(hdc, b.arr, b.n);
            PolyBezierTo(hdc, b.arr, b.n);
        }

        void SetBezierCurve(HDC hdc, POINT* arr, int n)
        {
            SetROP2(hdc, R2_NOTXORPEN);

            drawBezierCurve(hdc, BezierSD(n, arr, 0));

            drawBezierCurve(hdc, BezierSD(n, arr, 0));
        }
    }
}

#endif // DRAWING_H_INCLUDED

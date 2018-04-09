#ifndef TEMPLATE_FUNCTIONS_H_INCLUDED
#define TEMPLATE_FUNCTIONS_H_INCLUDED

#include <cmath>
#define pi 3.14

template<class T>
int sign(T x)
{
    return ((x < 0) ? -1 : 1);
}

template<class T>
T absVal(T x)
{
    return ((x < 0) ? -x : x);
}

template<class T>
T minimum(T a, T b)
{
    return ((a < b) ? a : b);
}

template<class T>
T maximum(T a, T b)
{
    return ((a > b) ? a : b);
}

template<class T>
bool In(T Xc, T Yc, T Radius, T Xs, T Ys, T Xe, T Ye)
{
    for(int angle = 0; angle < 360; angle++)
    {
        int Xi = Xc + Radius * cos(pi * angle / 180);
        int Yi = Yc + Radius * sin(pi * angle / 180);
        if (Xi >= Xs && Xi <= Xe && Yi >= Ys && Yi <= Ye) return true;
    }
    return false;
}

template<class T>
bool vertical(T Xc, T Yc, T Xs, T Ys, T Xe, T Ye)
{
    return (Xc < minimum(Xs, Xe) || Xc > maximum(Xs, Xe));
}

#endif // TEMPLATE_FUNCTIONS_H_INCLUDED

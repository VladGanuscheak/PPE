#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <windows.h>

void defaultBoolValue(bool* b1, bool* b2, bool* b3, bool* b4, bool* b5, bool* b6, bool* b7);

bool check(bool T, HWND hw);

template<class T>
T minimum(T a, T b);

template<class T>
T maximum(T a, T b);

template<class T>
T absVal(T x);

void DrawAgain(HWND hw);

void defaultBoolValue(bool* b1, bool* b2, bool* b3, bool* b4, bool* b5, bool* b6, bool* b7) // ÛÒÚ‡ÌÓ‚Í‡ «Õ¿◊≈Õ»… œŒ ”ÃŒÀ◊¿Õ»ﬁ
{
    *b1 = *b2 = *b3 = *b4 = *b5 = *b6 = false;
}
bool check(bool T, HWND hw)
{
    if (T) MessageBox(hw, "Figure can be used!", "FIGURE", NULL);
    else MessageBox(hw, "Cursor can be used!", "CURSOR", NULL);
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
T absVal(T x)
{
    return ((x < 0) ? -x : x);
}

void DrawAgain(HWND hw)
{
    InvalidateRect(hw, NULL, TRUE);
    UpdateWindow(hw);
}

int newColor(std::string s)
{
    int color = 255;
    int tenToPower = 1;
    int ans = 0;
    for(int i = minimum(2, (int)s.size() - 1); i >= 0; i--)
    {
        ans += (int)(s[i] - '0') * tenToPower;
        tenToPower *= 10;
    }
    ans %= 256;
    return ((!s.size()) ? 255 : ans);
}

#endif

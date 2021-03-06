#include <windows.h>
#include "defines.h"

void Stealth()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
}

LRESULT CALLBACK MainWinProc(
                             HWND,    // дескриптор окошка
                                      //
                             UINT,    // сообщение, посылаемое ОС
                                      //
                             WPARAM,  // параметры сообщений, для последующего обращения
                                      //
                             LPARAM   // параметры сообщений, для последующего обращения
                             );

int WINAPI WinMain(
                   HINSTANCE hInst, // дескриптор для данного экземпляра программы
                                    //
                   HINSTANCE hpi,   // в Win32 не используется (всегда NULL)
                                    //
                   LPSTR cmdline,   // командная строка
                                    //
                   int ss           // код состояния главного окна
                   )
{
    /* создаем и регистрируем класс главного окна */
    WNDCLASS wc;                                // Структура, которая содержит атрибуты класса окна
                                                //
    wc.style=0;                                 // Устанавливает стиль(и) класса. Этот член структуры
                                                // может быть любой комбинацией Стилей класса.
                                                //
    wc.lpfnWndProc=MainWinProc;                 // Указатель на оконную процедуру. Вы должны использовать
                                                // функцию CallWindowProc, чтобы вызвать оконную процедуру.
                                                //
    wc.cbClsExtra=wc.cbWndExtra=0;              // Устанавливает число дополнительных байт, которые
                                                // размещаются вслед за структурой класса окна.
                                                // Система инициализирует эти байты нулями.
                                                //
    wc.hInstance=hInst;                         // Дескриптор экземпляра, который содержит оконную
                                                // процедуру для класса.
                                                //
    wc.hIcon=LoadIcon(hInst,"Icon");;           // Дескриптор значка класса. Этот член структуры
                                                // должен быть дескриптором ресурса значка.
                                                // Если этот член структуры - ПУСТО (NULL), система
                                                // предоставляет заданный по умолчанию значок.
                                                //
    wc.hCursor=NULL;                            // Дескриптор курсора класса. Этот член структуры должен быть
                                                // дескриптором ресурса курсора. Если этот член структуры - ПУСТО (NULL),
                                                // приложение должно явно устанавливать форму курсора всякий раз,
                                                // когда мышь перемещается в окно прикладной программы.
                                                //
    wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);  // Дескриптор кисти фона класса. Этот член структуры может быть
                                                // дескриптором физической кисти, которая используется, чтобы красить
                                                // цветом фона, или это может быть кодом цвета. Код цвета должен быть
                                                // одним из ниже перечисленных стандартных системных цветов
                                                // (значение 1 должно добавляться к выбранному цвету).
                                                // Если дается код цвета, Вы должны преобразовать его в один из типов HBRUSH.
                                                //
    wc.lpszMenuName="Menu";                     // Указатель на символьную строку с символом конца строки ('\0') (нуль-терминатором),
                                                // которая устанавливает имя ресурса меню класса, которое как имя показывается в
                                                // файле ресурса. Если Вы используете целое число, чтобы идентифицировать меню,
                                                // используйте макрос MAKEINTRESOURCE. Если этот член структуры - ПУСТО (NULL),
                                                // окна, принадлежащие этому классу, не имеют никакого заданного по умолчанию меню.
                                                //
    wc.lpszClassName="MainWnd Class";           // Указатель на символьную строку с нулем в конце или  атом. Если этот параметр - атом,
                                                // это должен быть атом класса, созданный предыдущим вызовом функции RegisterClass или
                                                // RegisterClassEx. Атом должен находиться в младшем слове lpszClassName;
                                                // старшее слово должно быть нуль.

 if (!RegisterClass(&wc)) return FALSE;

 /* создаем главное окно и отображаем его */
    HWND hMainWnd=CreateWindow(
                                "MainWnd Class",           // указатель на зарегистрированное имя класса
                                                           //
                                "PPE lab4 Ganusceac Vlad", // указатель на имя окна
                                                           //
                                WS_OVERLAPPEDWINDOW,       // стиль окна
                                                           //
                                CW_USEDEFAULT,             // горизонтальная позиция окна
                                                           //
                                CW_USEDEFAULT,             // вертикальная позиция окна
                                                           //
                                CW_USEDEFAULT,             // ширина окна
                                                           //
                                CW_USEDEFAULT,             // высота окна
                                                           //
                                NULL,                      // дескриптор родительского или окна владельца
                                                           //
                                NULL,                      // дескриптор меню или ID дочернего окна
                                                           //
                                hInst,                     // дескриптор экземпляра приложения
                                                           //
                                NULL                       // указатель на данные создания окна
                                );

    Stealth();

    if (!hMainWnd) return FALSE;
    ShowWindow(hMainWnd,ss);
    UpdateWindow(hMainWnd);

    MSG msg; /* цикл обработки событий */
    while (GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

#include <windows.h>
#define ID_BUTTON1 1
#define ID_BUTTON2 2

/* the structure where I'll keep button's characteristics */
typedef struct button_characteristics
{
   int horizontal_position;                                                // the position of the left up corner of button on
                                                                           // Ox-axis projection
                                                                           //
   int vertical_position;                                                  // the position of the left up corner of button on
                                                                           // Oy-axis projection
                                                                           //
   int width;                                                              // the distance between left up and right up
                                                                           // corners on Ox-axis projection
                                                                           //
   int height;                                                             // the distance between left up and low up
                                                                           // corners on Oy-axis projection
                                                                           //

   button_characteristics(int hor_pos, int vert_pos, int wid, int hei)     // parametrized constructor
   :  horizontal_position(hor_pos)
   ,  vertical_position(vert_pos)
   ,  width(wid)
   ,  height(hei)
   {}
}bt;
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
                                "PPE lab1 Ganusceac Vlad", // указатель на имя окна
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

/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
    static HWND button1, button2;
    static bt bt1(25, 30, 100, 90);
    static bt bt2(135, 30, 100, 90);
    switch (msg)
    {
    case WM_CREATE:
        /* при создании окна внедряем в него кнопочку */
        button1 = CreateWindow(
                     "button",                           // указатель на зарегистрированное имя класса
                                                         //
                     "My button1",                       // указатель на имя окна
                                                         //
                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // стиль окна
                                                         //
                     bt1.horizontal_position,            // горизонтальная позиция окна
                                                         //
                     bt1.vertical_position,              // вертикальная позиция окна
                                                         //
                     bt1.width,                          // ширина окна
                                                         //
                     bt1.height,                         // высота окна
                                                         //
                     hw,                                 // дескриптор родительского или окна владельца
                                                         //
                     (HMENU)ID_BUTTON1,                  // дескриптор меню или ID дочернего окна
                                                         //
                     NULL,                               // дескриптор экземпляра приложения
                                                         //
                     NULL                                // указатель на данные создания окна
                     );
        /* стиль WS_CHILD означает, что это дочернее окно и для него
        вместо дескриптора меню будет передан целочисленный идентификатор,
        который будет использоваться дочерним окном для оповещения
        родительского окна через WM_COMMAND */
                button2 = CreateWindow(
                     "button",                           // указатель на зарегистрированное имя класса
                                                         //
                     "My button2",                       // указатель на имя окна
                                                         //
                     WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,  // стиль окна
                                                         //
                     bt2.horizontal_position,            // горизонтальная позиция окна
                                                         //
                     bt2.vertical_position,              // вертикальная позиция окна
                                                         //
                     bt2.width,                          // ширина окна
                                                         //
                     bt2.height,                         // высота окна
                                                         //
                     hw,                                 // дескриптор родительского или окна владельца
                                                         //
                     (HMENU)ID_BUTTON2,                  // дескриптор меню или ID дочернего окна
                                                         //
                     NULL,                               // дескриптор экземпляра приложения
                                                         //
                     NULL                                // указатель на данные создания окна
                     );
        return 0;
    case WM_COMMAND:
        if (HIWORD(wp)==0)
        {
            char buf[256];
            switch (LOWORD(wp))
            {
                case 7:  /* команда меню Exit */
                    PostQuitMessage(0);
                    break;
                case 8:
                    bt1 = bt(25, 30, 100, 90);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case 9:
                    bt1 = bt(25, 30, 120, 105);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case 10:
                    bt1 = bt(25, 30, 80, 70);
                    MoveWindow(button1, bt1.horizontal_position, bt1.vertical_position, bt1.width, bt1.height, TRUE);
                    break;
                case 11:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 30;
                        bt2 = bt(135, 30, 100, 90);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case 12:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 30;
                        bt2 = bt(135, 30, 120, 105);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case 13:
                    {
                        RECT rect = {0};
                        GetWindowRect(hw, &rect);
                        int xClient = rect.right - rect.left;
                        int yClient = rect.bottom - rect.top - 30;
                        bt2 = bt(135, 30, 80, 70);
                        MoveWindow(button2, xClient / 2 - bt2.width / 2, yClient / 2 - bt2.height / 2, bt2.width, bt2.height, TRUE);
                    }
                    break;
                case 14:
                    MoveWindow(hw, 0, 0, 450, 300, TRUE);
                    break;
                case 15:
                    MoveWindow(hw, 0, 0, 550, 420, TRUE);
                    break;
                case 16:
                    MoveWindow(hw, 0, 0, 700, 512, TRUE);
                    break;
                case 17:
                    MoveWindow(hw, 0, 0, 800, 600, TRUE);
                    break;
                case 18:
                    MoveWindow(hw, 0, 0, 1012, 700, TRUE);
                    break;
                default: /* все остальные команды */
                    wsprintf(buf,"Command code: %d",LOWORD(wp));
                    MessageBox(hw,buf,"MessageBox",MB_OK|MB_ICONINFORMATION);
            }
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
        /* пользователь закрыл окно, программа может завершаться */
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hw,msg,wp,lp);
}

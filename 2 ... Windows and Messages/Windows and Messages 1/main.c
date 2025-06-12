/*
 * This code is basically how your app gets its own spot in Windows and starts chilling.
 *
 * Imagine your app is like setting up a super cool pop-up shop:
 *
 * 1.  **`WNDCLASS` & `RegisterClass`:** You first design the *type* of shop you want.
 * You pick its look (background color, icon), decide how it acts (like if it resizes
 * when someone stretches it), and assign a "manager" (`WndProc`) to handle all the
 * customer interactions. Then, you tell the city (Windows) about your new shop design
 * so they know what's up.
 *
 * 2. `CreateWindow`: Once your shop type is registered, you actually build one of
 * those shops on a specific street corner. This is your app's main window popping up.
 *
 * 3. `ShowWindow` & `UpdateWindow`: You open the doors and make sure everything
 * looks fresh and visible to passersby.
 *
 * 4. The Message Loop (`GetMessage`, `TranslateMessage`, `DispatchMessage`): This is
 * the ongoing buzz inside your shop. The "manager" (`WndProc`) is constantly listening
 * for anything happening: someone clicks a button, types something, or even just moves
 * the window around. It's like the manager always being ready to handle customers, restock
 * shelves, or answer questions, keeping the shop running smoothly until you decide to close.
 *
 * In short: Your app registers its window 'style', builds the window, shows it off, and then
 * constantly listens for your clicks and moves, kinda like your phone always waiting for your taps!
 */


 /*

Windows API is huge! To keep things modular and efficient, Microsoft split its functions into different libraries:

- gdi32.lib (Graphics Device Interface): Contains functions for drawing on screen, handling fonts, colors, brushes, pens, and bitmaps. Think of it as the artist’s toolkit for Windows apps.

- winmm.lib (Windows Multimedia Library): Provides functions for multimedia tasks like playing sounds, recording audio, and working with joysticks or MIDI devices. This is the sound engineer’s toolkit.

By keeping these libraries separate, apps that don’t need multimedia won’t include that extra code, leading to smaller files and faster load times.

*/


#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWin");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    //You can comment out this line if you don't have the libraries gdi32.lib
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"),
            szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName, TEXT("The Hello Program"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    if (!hwnd)
        return 0;

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

   switch (message)
    {
    // You can comment out this part because PlaySound requires the winmm.lib library,
    // which is not linked by default in most Windows projects.
    // Unlike kernel32.lib, user32.lib, and gdi32.lib (which are included automatically),
    // winmm.lib is an external multimedia library that handles sounds and music.
    // If you don't link winmm.lib, calling PlaySound will cause linker errors.
    // So, unless you explicitly link winmm.lib in your project settings,
    // it's safer to comment out PlaySound to avoid build problems.
    case WM_CREATE:
        //PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hdc, TEXT("Hello, Windows 98!"), -1, &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}



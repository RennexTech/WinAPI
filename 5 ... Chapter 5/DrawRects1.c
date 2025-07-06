/*
This is just my test program, for drawing rectangles on the screen.
*/

#include <windows.h>

void DrawShapes(HWND hwnd) {
    HDC hdc = GetDC(hwnd);

    // Draw Rectangle
    Rectangle(hdc, 10, 20, 100, 150);
    Sleep(1000);  // Pause for 1 second

    // Clear the screen
    InvalidateRect(hwnd, NULL, TRUE);
    UpdateWindow(hwnd);
    Sleep(500);  // Pause for 0.5 seconds

    // Draw Ellipse
    Ellipse(hdc, 50, 50, 150, 100);
    Sleep(1000);  // Pause for 1 second

    // Clear the screen
    InvalidateRect(hwnd, NULL, TRUE);
    UpdateWindow(hwnd);
    Sleep(500);  // Pause for 0.5 seconds

    // Draw RoundRect
    RoundRect(hdc, 30, 30, 120, 90, 15, 20);
    Sleep(1000);  // Pause for 1 second

    ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE:
        SetTimer(hwnd, 1, 100, NULL);  // Set timer for 100 milliseconds
        return 0;

    case WM_TIMER:
        DrawShapes(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static TCHAR szAppName[] = TEXT("ShapesProgram");
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
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, TEXT("Program requires Windows NT!"), szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName, TEXT("Shapes Program"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        300, 300,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}


xCornerEllipse = (xRight - xLeft) / 4;
yCornerEllipse = (yBottom - yTop) / 4;





#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            // Draw a rectangle | Coordinates for the rectangle
            Rectangle(hdc, 50, 50, 150, 100);
            // Draw an ellipse | Coordinates for the ellipse
            Ellipse(hdc, 100, 150, 200, 250);
            // Draw a rounded rectangle | Coordinates and corner radii for the rounded rectangle
            RoundRect(hdc, 250, 50, 350, 100, 20, 20);
            // Draw an arc |  Coordinates, starting point, and ending point for the arc
            Arc(hdc, 400, 50, 500, 100, 425, 75, 475, 75);
            // Draw a chord | Coordinates, starting point, and ending point for the chord
            Chord(hdc, 400, 150, 500, 200, 425, 175, 475, 175);
            // Draw a pie slice | Coordinates, starting point, and ending point for the pie slice
            Pie(hdc, 400, 250, 500, 300, 425, 275, 475, 275);
            EndPaint(hwnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}









































































































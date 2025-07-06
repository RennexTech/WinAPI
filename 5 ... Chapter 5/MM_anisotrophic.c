/*


*/


#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Window Initialization Code (CreateWindow, ShowWindow, etc.)

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static int cxClient, cyClient;

    switch (uMsg) {
        case WM_CREATE:
            // Initialization code if needed
            break;

        case WM_SIZE:
            cxClient = LOWORD(lParam);
            cyClient = HIWORD(lParam);
            break;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Set MM_ANISOTROPIC mapping mode
            SetMapMode(hdc, MM_ANISOTROPIC);

            // Scenario 1: Arbitrary Coordinates
            SetWindowExtEx(hdc, 32767, 32767, nullptr);
            SetViewportExtEx(hdc, cxClient, -cyClient, nullptr);
            SetViewportOrgEx(hdc, 0, cyClient, nullptr);
            Rectangle(hdc, -5000, -5000, 5000, 5000);

            // Scenario 2: Clock Drawing
            SetWindowExtEx(hdc, 1000, 1000, nullptr);
            SetViewportExtEx(hdc, cxClient / 2, -cyClient / 2, nullptr);
            SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, nullptr);
            Ellipse(hdc, -500, -500, 500, 500);

            // Scenario 3: Text Display
            SetWindowExtEx(hdc, 1, 1, nullptr);
            SetViewportExtEx(hdc, cxClient, cyClient, nullptr);
            TextOut(hdc, 3, 2, TEXT("Hello"), 5);

            EndPaint(hwnd, &ps);
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

/*


The provided code is a Windows application written in C++ using the WINAPI, showcasing the MM_ANISOTROPIC mapping mode and its various applications. Let's delve into each scenario in depth:

Arbitrary Coordinates (Scenario 1):

In this scenario, the code sets up the MM_ANISOTROPIC mapping mode with arbitrary coordinates, similar to MM_ISOTROPIC. The logical window size and viewport size are defined based on the client area, allowing for the drawing of a rectangle. Unlike MM_ISOTROPIC, MM_ANISOTROPIC does not adjust for aspect ratio, resulting in potential distortions if the client area is not square.
Clock Drawing (Scenario 2):

This section demonstrates the use of MM_ANISOTROPIC to draw a clock-like shape, specifically an ellipse. The code sets up the mapping mode with fixed but unequal values for x and y units, showcasing that MM_ANISOTROPIC does not maintain the correct aspect ratio. As a result, the clock is drawn as an ellipse rather than a circle.
Text Display (Scenario 3):

The code illustrates another use of MM_ANISOTROPIC, where x and y units are set to fixed but unequal values, particularly suitable for displaying text. In this scenario, the coordinates are specified in terms of character rows and columns, allowing for the placement of text in the client area. This approach is especially relevant when working with fixed-point fonts.
Unlocking Extents:

The final part of the code demonstrates how MM_ANISOTROPIC can be used to "unlock" the extents of an otherwise fully-constrained mapping mode. By initially setting another mapping mode (MM_LOENGLISH) and then switching to MM_ANISOTROPIC, the code allows changes to the extents. This flexibility is useful when specific orientation preferences, such as MM_TEXT, need to be combined with other mapping modes.

In summary, the code provides a comprehensive overview of the MM_ANISOTROPIC mapping mode, showcasing its versatility in handling various coordinate scenarios and emphasizing its unique feature of not adjusting values set by the programmer, allowing for greater flexibility in mapping logical to physical coordinates.

*/

//Program 2

#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    HDC hdc;
    LONG cxClient, cyClient;

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "MM_ANISOTROPIC", "MM_ANISOTROPIC", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    if (!hwnd)
    {
        return FALSE;
    }

    hdc = GetDC(hwnd);

    if (!hdc)
    {
        return FALSE;
    }

    cxClient = GetSystemMetrics(SM_CXCLIENT);
    cyClient = GetSystemMetrics(SM_CYCLIENT);

    // Set the mapping mode to MM_ANISOTROPIC.
    SetMapMode(hdc, MM_ANISOTROPIC);

    // Set the window extents to 32,767 x 32,767 logical units.
    SetWindowExtEx(hdc, 32767, 32767, NULL);

    // Set the viewport extents to the width and height of the client area in pixels.
    SetViewportExtEx(hdc, cxClient, -cyClient, NULL);

    // Set the viewport origin to the lower left corner of the client area.
    SetViewportOrgEx(hdc, 0, cyClient, NULL);

    // Draw a red line from (0, 0) to (32767, 32767).
    SetPenColor(hdc, RGB(255, 0, 0));
    MoveToEx(hdc, 0, 0, NULL);
    LineToEx(hdc, 32767, 32767, NULL);

    // Draw a green line from (32767, 0) to (0, 32767).
    SetPenColor(hdc, RGB(0, 255, 0));
    MoveToEx(hdc, 32767, 0, NULL);
    LineToEx(hdc, 0, 32767, NULL);

    // Draw a blue circle with a diameter of 10,000 logical units.
    SetPenColor(hdc, RGB(0, 0, 255));
    Ellipse(hdc, 16384, 16384, 26384, 26384);

    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);

    return 0;
}

/*
Explanation:

The code sets the mapping mode to MM_ANISOTROPIC using the SetMapMode function.

The code sets the window extents to 32,767 x 32,767 logical units using the SetWindowExtEx function.

The code sets the viewport extents to the width and height of the client area in pixels using the SetViewportExtEx function.

The code sets the viewport origin to the lower left corner of the client area using the SetViewportOrgEx function.

The code draws a red line from (0, 0) to (32,767, 32,767) using the SetPenColor, MoveToEx, and LineToEx functions.

The code draws a green line from (32,767, 0) to (0, 32,767) using the SetPenColor, MoveToEx, and LineToEx functions.

The code draws a blue circle with a diameter of 10,000 logical units using the SetPenColor and Ellipse functions.
*/






























































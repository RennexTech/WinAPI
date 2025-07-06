//These 2 pieces of code is for working with MM_ISOTROPHIC coz it has so many sub-concepts within it.

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

            // Set MM_ISOTROPIC mapping mode
            SetMapMode(hdc, MM_ISOTROPIC);

            // Set logical window size and viewport size based on client area
            SetWindowExtEx(hdc, 32767, 32767, nullptr);
            SetViewportExtEx(hdc, cxClient, -cyClient, nullptr);

            // Center the logical window in the client area
            SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, nullptr);

            // Draw something using logical coordinates
            // For simplicity, let's draw a rectangle
            Rectangle(hdc, -5000, -5000, 5000, 5000);

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

The code, sets up the MM_ISOTROPIC Mode:

The code includes the line SetMapMode(hdc, MM_ISOTROPIC);, explicitly setting the mapping mode to MM_ISOTROPIC.

Adjusting Logical and Physical Extents:
The code uses SetWindowExtEx and SetViewportExtEx functions to set logical window size and viewport size based on the client area. This demonstrates the flexibility provided by MM_ISOTROPIC in adjusting the scaling factors for logical coordinates.

Centering the Logical Window:
The line SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, nullptr); centers the logical window in the client area. In MM_ISOTROPIC mode, this ensures that logical units on both axes represent equal physical distances, maintaining the isotropic nature.

Drawing with Logical Coordinates:
The code performs a drawing operation (drawing a rectangle) using logical coordinates within the MM_ISOTROPIC mapping mode. This highlights the capability of MM_ISOTROPIC to allow drawing shapes with equal logical widths and heights as squares or circles.

MORE EXPLANATION:

WinMain function:
The WinMain function is the entry point for the Windows application. It initializes the window and enters a message loop using GetMessage to handle messages.

WindowProc Function:
WindowProc is the window procedure that handles messages for the application window.

WM_CREATE:
The WM_CREATE message is received when the window is created. Initialization code can be placed here if needed.

WM_SIZE:
The WM_SIZE message is received when the window is resized. The client area dimensions are stored in cxClient and cyClient variables.

WM_PAINT:
The WM_PAINT message is received when the window needs repainting. Inside this block:
The device context (hdc) is obtained using BeginPaint.
SetMapMode sets the mapping mode to MM_ISOTROPIC.

SetWindowExtEx and SetViewportExtEx set logical window and viewport sizes based on the client area.

SetViewportOrgEx centers the logical window in the client area.

A rectangle is drawn using logical coordinates, in this case, a rectangle with corners at (-5000, -5000) and (5000, 5000).
EndPaint signals the end of painting.

WM_DESTROY:
The WM_DESTROY message is received when the window is being destroyed. PostQuitMessage(0) posts a quit message to exit the message loop.

Default Case:
The DefWindowProc is called for any unhandled messages.

In summary, this code creates a window, sets up a message loop, and demonstrates the use of the MM_ISOTROPIC mapping mode to draw a rectangle in the center of the window, adjusting to changes in the window size.
*/

//Program 2

#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    HDC hdc;
    LONG cxClient, cyClient;

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "MM_ISOTROPIC", "MM_ISOTROPIC", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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

    // Set the mapping mode to MM_ISOTROPIC.
    SetMapMode(hdc, MM_ISOTROPIC);

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
This program 2 will create a window and draw a red line from (0, 0) to (32,767, 32,767), a green line from (32,767, 0) to (0, 32,767), and a blue circle with a diameter of 10,000 logical units. The lines and circle will be drawn to the center of the window.

Here is a breakdown of the code:

The SetMapMode function is used to set the mapping mode to MM_ISOTROPIC.

The SetWindowExtEx function is used to set the window extents to 32,767 x 32,767 logical units.

The SetViewportExtEx function is used to set the viewport extents to the width and height of the client area in pixels.

The SetViewportOrgEx function is used to set the viewport origin to the lower left corner of the client area.

The SetPenColor function is used to set the pen color to the desired color.

The MoveToEx function is used to set the current position of the pen to the desired logical coordinates.

The LineToEx function is used to draw a line from the current position of the pen to the desired logical coordinates.

The Ellipse function is used to draw an ellipse with the desired rectangular frame.

Notable differences:

Window Creation:

In this code, CreateWindowEx is used to create a window with the extended style WS_EX_CLIENTEDGE and the window class name "MM_ISOTROPIC." The previous code did not explicitly create a window class, and the window class name was not "MM_ISOTROPIC."
Drawing Elements:

This code draws a red line from (0, 0) to (32767, 32767), a green line from (32767, 0) to (0, 32767), and a blue circle with a diameter of 10,000 logical units. The previous code drew a simple rectangle for demonstration purposes.
Pen Color Setting:

This code uses a SetPenColor function (which is not a standard Windows API function) to set the pen color before drawing lines and a circle. The previous code did not include a custom function for setting pen color.
Cleanup:

This code releases the device context (ReleaseDC) and destroys the window (DestroyWindow) before returning from the WinMain function. The previous code had a message loop (GetMessage loop) and used PostQuitMessage to terminate the application.

In summary, while both codes demonstrate the use of the MM_ISOTROPIC mapping mode and drawing elements using logical coordinates, they have differences in window creation, drawing elements, and cleanup procedures. The primary purpose of both codes is to illustrate the usage of the MM_ISOTROPIC mapping mode in a Windows application.

*/


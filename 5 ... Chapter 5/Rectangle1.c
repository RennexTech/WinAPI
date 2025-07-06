#include <windows.h>

int main() {
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetDC(hwnd);

    RECT rect;
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));

    // FillRect example
    SetRect(&rect, 10, 10, 100, 100);
    FillRect(hdc, &rect, brush);

    // FrameRect example
    SetRect(&rect, 20, 20, 120, 120);
    FrameRect(hdc, &rect, brush);

    // InvertRect example
    SetRect(&rect, 30, 30, 130, 130);
    InvertRect(hdc, &rect);

    // SetRect example
    SetRect(&rect, 40, 40, 140, 140);
    SetRect(&rect, 10, 10, 50, 50);

    // OffsetRect example
    OffsetRect(&rect, 20, 20);

    // InflateRect example
    InflateRect(&rect, 10, 10);

    // SetRectEmpty example
    SetRectEmpty(&rect);

    // CopyRect example
    RECT destRect;
    CopyRect(&destRect, &rect);

    // IntersectRect example
    RECT rect1, rect2;
    SetRect(&rect1, 10, 10, 50, 50);
    SetRect(&rect2, 20, 20, 60, 60);
    IntersectRect(&destRect, &rect1, &rect2);

    // UnionRect example
    UnionRect(&destRect, &rect1, &rect2);

    // IsRectEmpty example
    BOOL bEmpty = IsRectEmpty(&destRect);

    // PtInRect example
    POINT pt;
    pt.x = 30;
    pt.y = 30;
    BOOL bInRect = PtInRect(&destRect, pt);

    ReleaseDC(hwnd, hdc);
    DeleteObject(brush);

    return 0;
}


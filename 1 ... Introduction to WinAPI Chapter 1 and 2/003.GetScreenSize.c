/*
-------------------------------------------------------------
ScreenSizeMsg.c – Shows screen resolution in a Windows message box
Your app’s first step into dynamic content. Let's go. 💻📏
-------------------------------------------------------------
*/

#include <windows.h>   // Core Windows functions
#include <tchar.h>     // For portable string macros (TEXT, TCHAR, etc.)
#include <stdio.h>     // For formatted output (sprintf-style functions)

// 🧠 MessageBoxPrintf: Like printf() but in pop-up form.
// Accepts a title (caption), a format string, and unlimited arguments.
// Think of it as printf’s extroverted cousin—it likes to shout things in a dialog box.

int CDECL MessageBoxPrintf(TCHAR *szCaption, TCHAR *szFormat, ...)
{
    TCHAR szBuffer[1024];     // Buffer to hold final message
    va_list pArgList;         // To handle variable number of arguments

    // 🔧 va_start: Initializes the list of additional arguments
    va_start(pArgList, szFormat);

    // 🧪 _vsntprintf: Format the string just like printf, but safe for TCHAR
    _vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);

    // ✅ va_end: Clean up after we’re done with the arguments
    va_end(pArgList);

    // 💬 MessageBox: Show the formatted message in a Windows dialog
    return MessageBox(NULL, szBuffer, szCaption, 0);
}

// 🚀 WinMain: This is where the Windows app takes off.
// It's like clicking "Launch" on your favorite app—this is the start button.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    int cxScreen, cyScreen;

    // 🖥️ Get screen width and height in pixels
    cxScreen = GetSystemMetrics(SM_CXSCREEN);  // Width
    cyScreen = GetSystemMetrics(SM_CYSCREEN);  // Height

    // 📢 Show it in a message box with custom formatting
    MessageBoxPrintf(TEXT("ScrnSize"),
                     TEXT("The screen is %i pixels wide by %i pixels high."),
                     cxScreen, cyScreen);

    return 0; // Peace out gracefully
}

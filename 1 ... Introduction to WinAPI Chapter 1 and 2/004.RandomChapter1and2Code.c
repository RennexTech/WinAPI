/*
-------------------------------------------------------------
Example 1 – Basic MessageBox with sprintf
-------------------------------------------------------------
*/

#include <windows.h>
#include <stdio.h> // Needed for sprintf

int main()
{
    char szBuffer[100];

    // 🎯 sprintf: Formats a string and stores it in szBuffer
    // It's like pre-writing your message before showing it.
    sprintf(szBuffer, "This is a message box.");

    // 💬 MessageBox: Pops up a dialog box with your message
    // NULL = no parent window (just show it directly)
    // "My Program" = the title at the top of the box
    // MB_OK = only show an "OK" button
    MessageBox(NULL, szBuffer, "My Program", MB_OK);

    return 0; // Done — app exits clean
}

/*
🎉 Bonus Fun Constants (not used, just for vibes)
-------------------------------------------------
#define AGE 12             // Could represent a variable like user age
#define PERCENTAGE 100     // Full marks 💯
#define TEETH 32           // A full smile (dentist approved 😁)
#define PI 3.1459          // Close enough for casual use (not math class lol)
*/

/*
-------------------------------------------------------------
Example 2 – Wide Character Support (Unicode-style strings)
-------------------------------------------------------------
*/

#include <wctype.h>
#include <wchar.h>

int main() {
    wchar_t szBuffer[100];            // Buffer to store the final message
    wchar_t szFormat[] = L"Hello, %ls!"; // Format string, L = wide string literal

    // 🧠 swprintf: Just like sprintf, but for wide (Unicode) characters
    // Good for internationalization and supporting non-English alphabets
    swprintf(szBuffer, sizeof(szBuffer)/sizeof(wchar_t), szFormat, L"world!");

    // 👀 wprintf: Print to console using wide characters
    wprintf(L"%s\n", szBuffer); // Output: Hello, world!

    return 0;
}

/*
-------------------------------------------------------------
Example 3 – MessageBoxPrintf (Custom popup printf)
-------------------------------------------------------------
*/

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

// 🧩 MessageBoxPrintf: A reusable function that works like printf
// but shows the formatted text in a MessageBox popup.
// Makes it easier to reuse in any part of your app.
int CDECL MessageBoxPrintf(TCHAR *szCaption, TCHAR *szFormat, ...)
{
    TCHAR szBuffer[1024];   // Final message string
    va_list pArgList;       // List of additional arguments (variable arguments)

    // 🔧 va_start: Initializes the va_list to read the additional arguments
    // It basically points to the memory location right after szFormat.
    va_start(pArgList, szFormat);

    // 🧪 _vsntprintf: Formats the arguments into szBuffer
    // It works like sprintf but safer, because we control the buffer size.
    _vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);

    // 🧼 va_end: Always call this after you're done with va_list
    // It "cleans up" — not mandatory in most modern compilers,
    // but good practice and ensures compatibility with different systems.
    va_end(pArgList);

    // 💬 Show the final formatted string in a pop-up
    return MessageBox(NULL, szBuffer, szCaption, 0);
}

// 🚀 WinMain: The starting point of your GUI-based Windows app.
// It's where the OS calls when your app starts running.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    // 📐 Get screen dimensions
    // These return the screen width and height in pixels
    int cxScreen = GetSystemMetrics(SM_CXSCREEN);
    int cyScreen = GetSystemMetrics(SM_CYSCREEN);

    // 📢 Display the screen dimensions using the custom popup function
    MessageBoxPrintf(
        TEXT("ScrnSize"),
        TEXT("The screen is %i pixels wide by %i pixels high."),
        cxScreen, cyScreen
    );

    return 0; // Exit app cleanly
}

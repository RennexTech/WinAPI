/*
-------------------------------------------------------------
TCHAR Demo – Making Your Strings Work in Both ANSI & Unicode
-------------------------------------------------------------
*/

#include <stdio.h>   // For standard input/output functions
#include <tchar.h>   // Adds support for TCHAR, _tprintf, _T(), etc.

int main() {
    // 🧩 TCHAR is a special type that adjusts based on how your app is compiled:
    // If your app uses normal characters (ASCII), TCHAR = char
    // If your app uses Unicode (wide characters), TCHAR = wchar_t
    //
    // That means this code works in both cases — kind of like writing once, running in two modes.

    // 🔤 Define a string using TCHAR
    TCHAR str[] = _T("Hello, World!");
    // _T() macro ensures the string works in both Unicode and non-Unicode builds

    // 🖨️ Print the string using _tprintf
    // This is the TCHAR version of printf (adjusts to char or wchar_t)
    _tprintf(_T("String: %s\n"), str);

    // 📏 Get the length of the string
    size_t length = _tcslen(str); // _tcslen = "TCHAR string length"
    _tprintf(_T("String Length: %zu\n"), length); // %zu = print a size_t number

    return 0; // Done!
}

/*
-------------------------------------------------------------
WideCharDemo.c – Playing with wide characters + Windows pop-up
-------------------------------------------------------------
*/

#include <stdio.h>      // For console printing (wprintf)
#include <stdlib.h>     // General utilities (not used here, but standard)
#include <wchar.h>      // For wide character support
#include <windows.h>    // For Windows API (MessageBox)

int main()
{
    // 🖥️ Print to the console using wide characters
    // L"" = wide string literal. wprintf is used for Unicode/UTF-16
    wprintf(L"Hello, world!\n");

    // 🔤 Define a single wide character variable
    wchar_t c = L'A'; // 'A' stored in wide char (2 bytes instead of 1)

    // 🧭 Define a pointer to a wide string
    wchar_t *p;

    // ⚙️ Initialize that pointer to point to a wide string
    p = L"Hello!"; // L before the string = "this is Unicode, baby"

    // 🧳 Create an empty array of 10 wide characters (uninitialized)
    wchar_t a[10]; // You can store 10 Unicode characters here

    // 📦 Create and initialize a wide char array with a message
    wchar_t b[] = L"Hello!"; // Same as p, but stored in array instead of pointer

    // 🪟 Show a message box popup using Windows API
    // TEXT() macro ensures the string works with both Unicode and ANSI
    MessageBox(NULL, TEXT("Hello, world!"), TEXT("HelloMsg"), MB_OK);

    return 0; // ✅ App exits clean
}

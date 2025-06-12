// _tmain and _T: The entry point for programs that wanna handle both regular and wide characters smoothly

#include <tchar.h>  // Helps your program work with both char (ASCII) and wchar_t (Unicode) strings without extra hassle
#include <stdio.h>  // For printing stuff to the console

// _tmain is like main(), but smarter — it knows if your program uses ASCII or Unicode text
int _tmain(int argc, _TCHAR* argv[]) {
    // _tprintf prints text that works for both regular strings and wide strings
    // Regular strings = plain old ASCII characters (1 byte per char, like basic English letters)
    // Wide strings = Unicode characters (can handle emojis, symbols, and letters from all languages)
    // _T wraps your strings to make them work as ASCII or Unicode depending on your project settings
    _tprintf(_T("Hello, %s!\n"), _T("World"));  
    
    return 0;  // Program finished — all good
}

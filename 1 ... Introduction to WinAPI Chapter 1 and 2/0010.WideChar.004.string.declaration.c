// String Declarations: Your text’s vibe check — which string fits your style?

#include <windows.h> // Core stuff for Windows programming

int main() {
    // Normal string: plain old ASCII text, one byte per character(8bits in ASM).
    // This means it can handle English letters, numbers, and basic symbols.
    // Think simple text like "Hello, world!" — fits in 1 byte per character.
    char *string_char = "Hello, world!";

    // Wide string: prefix with L to handle Unicode characters.
    // Unicode means it supports way more characters than ASCII,
    // like Arabic, Chinese, emojis — basically global languages and symbols.
    // These use more memory per character (usually 2 or 4 bytes).
    wchar_t *string_wchar = L"Hello, world!";

    // TCHAR string: This is a "chameleon" string type.
    // It switches between char or wchar_t depending on your project setup.
    // The TEXT() macro helps with this magic — 
    // so TEXT("Hello, world!") becomes the right string type automatically.
    // This way, your code can work with ASCII or Unicode without changes.
    TCHAR *string_tchar = TEXT("Hello, world!");

    // Later, you can use these strings in Windows UI functions like MessageBox:
    // MessageBox(NULL, string_tchar, TEXT("Title"), MB_OK);

    return 0; // All done here.
}

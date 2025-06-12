/*
-------------------------------------------------------------
String Lengths in C: Regular vs. Wide (Unicode-friendly)
-------------------------------------------------------------
*/

#include <stdio.h>    // For printf() - basic output to the console
#include <wchar.h>    // For wide character support (wchar_t, wcslen)
#include <string.h>   // For strlen() - gets regular string lengths

int main() {
    // 👇 REGULAR STRING (char *)
    // Create a pointer called pc, and point it to the string "Hello!"
    // This means: pc is a pointer variable, meaning it stores the memory address where the string "Hello!" starts.
    // Like writing down where your favorite snack is hidden 🍪📍 — so the variable itself holds something like 0xFFFFFFFF (an address in memory).
    char *pc = "Hello!"; // 1 byte per character (ASCII)


    // strlen() calculates how many characters before it hits the null terminator '\0'
    int length1 = strlen(pc);

    // 👇 WIDE STRING (wchar_t *)
    // Same idea as above, but this string is wide — more bytes per character
    // Useful for international text, emojis, and non-English alphabets
    wchar_t *pw = L"Hello!"; // L before the string means it's a wide string

    // wcslen() works just like strlen but for wide strings
    int length2 = wcslen(pw);

    // 🖨️ Print both lengths to see they match (both should be 6 for "Hello!")
    printf("Character string length: %d\n", length1);
    printf("Wide character string length: %d\n", length2);

    return 0; // Peace out, program done 😎
}

/*
-------------------------------------------------------------
ConsoleAddition.c – Basic console I/O with a sprinkle of WinAPI
This version uses text prompts in the terminal to do addition.
-------------------------------------------------------------
*/

#include <stdio.h>      // Standard input/output (printf, scanf)
#include <windows.h>    // Windows API – using it here for Sleep()

// Function prototype
int addition(int a, int b);

int main()
{
    // 🕹️ Starting point for the console app
    printf("Performing addition...\n");

    // 💤 Sleep for 2 seconds (2000 ms)
    // Windows API function – gives the program a pause
    Sleep(2000);

    // 🚀 Call the addition function (user enters numbers there)
    int result = addition(2, 3);

    // 🎯 Output the result to the terminal
    printf("Your summation: %d\n", result);

    return 0;
}

// 📥 addition() – handles user input and returns the sum
int addition(int a, int b)
{
    // Prompts for input, reads into b and a
    // ⚠️ The order might look reversed – intentional or oversight?
    // In this order, b is entered first, then a.

    printf("Enter the first number: ");
    scanf_s("%d", &b);  // Safer version of scanf (Microsoft-specific)

    printf("Enter the second number: ");
    scanf_s("%d", &a);

    // ➕ Return the sum of the two inputs
    return a + b;
}

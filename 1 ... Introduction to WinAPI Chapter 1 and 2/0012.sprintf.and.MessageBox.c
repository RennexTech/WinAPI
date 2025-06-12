// sprintf and MessageBox Combo

#include <windows.h> // Windows pop-ups and stuff
#include <stdio.h>   // For sprintf, which builds strings with variables

int main() {
    char szBuffer[100]; // A place in memory to build your message string

    // What does sprintf do?
    // Think of sprintf like a template-filler.
    // You give it a template string with placeholders (like %i), and then the values to put in those placeholders.
    // %i means "insert an integer here".
    // So sprintf(szBuffer, "Sum of %i and %i is %i", 5, 3, 8) builds the string:
    // "Sum of 5 and 3 is 8" and stores it in szBuffer.

    sprintf(szBuffer, "Sum of %i and %i is %i", 5, 3, 5 + 3);

    // Now, szBuffer contains: "Sum of 5 and 3 is 8"
    // MessageBox will pop up this message.
    MessageBox(NULL, szBuffer, TEXT("My Program"), MB_OK);

    // Another example: formatting a string with a float and string
    char szInfo[100];
    float pi = 3.14159f;
    char name[] = "Alice";

    // %f is for floating point numbers, %s is for strings
    sprintf(szInfo, "%s loves the number %.2f", name, pi);
    // This creates "Alice loves the number 3.14"
    MessageBox(NULL, szInfo, TEXT("Fun Example"), MB_OK);

    return 0; // All done here!
}


/**
 * 
 * Why use sprintf?
 * 
 * It builds a complete message string from variables you have — 
 * 
 * like making a custom text message before showing it.
 * 
 * This way, you don’t have to manually create long strings with 
 * 
 * a bunch of + operators or string concatenations — sprintf handles it cleanly and quickly.
 * 
 */

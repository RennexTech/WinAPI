// MessageBox Results & lstrcpy: What’s going on here?

#include <windows.h> // This includes all the Windows functions you need.

int main() {
    // Show a message box with an OK button.
    // MessageBox returns a number that tells us which button the user clicked.
    int result = MessageBox(NULL, TEXT("This is a messagebox."), TEXT("My Program"), MB_OK);

    // Check if the user clicked the OK button. IDOK is a special constant that means the OK button.
    if (result == IDOK) { 
        // If they did, you can run some code here — like saying "Thanks for clicking OK!"
        // For now, nothing happens, but this is where your cool stuff goes.
    }

    // lstrcpy is like copy-paste for strings in Windows.
    // It copies one string into another spot in memory.
    char sourceString[] = "This is a source string.";   // This is the original text.
    char destinationString[100];                         // This is where we want to copy the text.

    // Copy the text from sourceString into destinationString.
    lstrcpy(destinationString, sourceString);

    // If you want to check the copy worked, you could print it out like this:
    printf("Copied text: %s\n", destinationString);

    return 0; // The program ends here.
}

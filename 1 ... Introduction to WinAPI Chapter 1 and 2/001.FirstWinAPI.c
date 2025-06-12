/*------------------------------------------------------------
HelloMsg.c – Displays "Hello, Windows 11!" in a message box
Based on Charles Petzold’s classic example (c) 1998
Updated for vibes in 2025 ✨

// Note that the labelling of the pdfs doesn't go hand in hand with the .c files.
// So once you read a subtopic, you actually check which .c file belongs to that subtopic. 
------------------------------------------------------------*/

#include <windows.h>

// This is where your Windows app officially kicks off.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    // Pop-up time: Display a message box saying hello.
    MessageBox(NULL, TEXT("Hello, Windows 11!"), TEXT("MyFirstGUI"), 0);
    return 0; // Peace out. App exits clean.
}

/*
────────────────────────────────────────────
🧠 EXPLAINED (Professional + Chill Edition)
────────────────────────────────────────────

#include <windows.h>
→ Loads the Windows API toolkit. Think of it like importing the "tools and gadgets" you need to build a Windows app.
(Professional: This header defines all core functions, types, constants for Win32 apps.)

────────────────────────────────────────────
🚀 WinMain – The Launchpad
────────────────────────────────────────────
int WINAPI WinMain(
    HINSTANCE hInstance,        // ID for your app's current instance
    HINSTANCE hPrevInstance,    // Always NULL now; legacy from Windows 3.x days
    PSTR szCmdLine,             // Command-line args (as one string)
    int iCmdShow                // Tells Windows how to show your app (e.g., minimized/maximized)
)

→ This is the entry point for GUI apps on Windows.
(Gen Z: Think of it like tapping “Open App” on your phone—this is where your code wakes up and says “let’s go!”)

────────────────────────────────────────────
💬 MessageBox – Your App’s First DM
────────────────────────────────────────────
MessageBox(
    NULL,                       // No parent window → just throw it center stage
    TEXT("Hello, Windows 11!"),// Message content – your "what’s up"
    TEXT("MyFirstGUI"),        // Title bar text – sender name in the pop-up
    0                          // Flags (0 = default OK button)
);

→ Pops up a simple dialog. Great for debugging, greetings, or “Hey, something happened!” alerts.
(Relatable: Like a text notification from an app that just wants to say hi.)

────────────────────────────────────────────
🔚 return 0;
────────────────────────────────────────────
→ Closes the app cleanly. No crashes. No drama.
(Like ending a call with “Alright, talk later ✌️”)

────────────────────────────────────────────
🧾 HEADER FILE INSIGHTS (Where All the Magic Lives)
────────────────────────────────────────────

All Windows C programs pull in headers like:

- WINDEF.H: Core types (DWORD, BOOL, etc.)
- WINNT.H: Unicode and OS-level types
- WINBASE.H: Low-level system calls
- WINUSER.H: UI functions (like MessageBox)
- WINGDI.H: Graphics and drawing APIs

👨‍💻 Pro tip: Use "Find in Files" in Visual Studio to explore these headers. It’s like checking the source code behind your favorite app feature.

────────────────────────────────────────────
🎯 TL;DR:
────────────────────────────────────────────
- This is your classic “Hello World” app, Windows edition.
- It teaches how GUI apps start (`WinMain`) and how to talk to users (`MessageBox`).
- Runs instantly, no window needed—just a polite little pop-up.

Next time you build a full app? This is where it all begins.

*/


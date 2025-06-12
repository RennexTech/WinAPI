/*-------------------------------------------------------------

HelloMsg.c – Displays a simple message box in Windows

Based on Charles Petzold's original (c) 1998

-------------------------------------------------------------*/

/*
 * WinMain – This is your app’s entry point in a Windows GUI environment.
 * (Think of it as pressing "Start Stream"—this is when your app goes live.)

 * Parameters:
 *  - hInstance: Handle to the current app instance (your app’s unique ID).
 *  - hPrevInstance: Legacy stuff. Not used anymore. (Just ignore it.)
 *  - lpCmdLine: Command-line args as a string.
 *  - nShowCmd: Tells Windows how to show your app's window (e.g., minimized, maximized).

 * MessageBox – Pops up a simple dialog.
 * Parameters:
 *  - NULL: No parent window. Pop it standalone. (Front and center like a bold text alert.)
 *  - TEXT("Hello, Windows!"): The actual message. (Your "what’s up?" to the user.)
 *  - TEXT("HelloMsg"): Title of the message box. (Like a sender name.)
 *  - 0 / MB_OK / other flags: Controls buttons/icons. (Customizes the vibe!)
 */

#include <windows.h>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd
) {
    MessageBox(NULL, TEXT("Hello, Windows!"), TEXT("HelloMsg"), MB_OK);
    return 0;
}

/*
 * Alternative entry point: main()
 * Works in console apps. MessageBox still works, just no full Windows GUI setup.
 */
int main() {
    MessageBox(NULL, TEXT("Hello, world!"), TEXT("HelloMsg"), MB_OK);
    return 0;
}

/*
 * MessageBox Button Options:
 * Use these to choose what kind of buttons your pop-up shows.
 * Like picking a response style on a notification.
 */

#define MB_OK                   0x00000000L  // Only "OK"
#define MB_OKCANCEL             0x00000001L  // "OK" + "Cancel"
#define MB_ABORTRETRYIGNORE     0x00000002L  // "Abort", "Retry", "Ignore"
#define MB_YESNOCANCEL          0x00000003L  // "Yes", "No", "Cancel"
#define MB_YESNO                0x00000004L  // "Yes" + "No"
#define MB_RETRYCANCEL          0x00000005L  // "Retry" + "Cancel"

/*
 * Default Button Settings:
 * Decide which button gets highlighted by default.
 */

#define MB_DEFBUTTON1           0x00000000L  // First button
#define MB_DEFBUTTON2           0x00000100L  // Second button
#define MB_DEFBUTTON3           0x00000200L  // Third button
#define MB_DEFBUTTON4           0x00000300L  // Fourth button (rare)

/*
 * Icon Styles:
 * Choose what icon appears in the dialog.
 * (Sets the tone—serious, fun, alert, etc.)
 */

#define MB_ICONHAND             0x00000010L  // Red X (error)
#define MB_ICONQUESTION         0x00000020L  // Question mark
#define MB_ICONEXCLAMATION      0x00000030L  // Yellow triangle (!)
#define MB_ICONASTERISK         0x00000040L  // Info icon (i)

/*
 * Pro tip: You can combine options using bitwise OR.
 * Example: MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2
 * Shows Yes/No with a question icon, defaulting to the second button.
 */

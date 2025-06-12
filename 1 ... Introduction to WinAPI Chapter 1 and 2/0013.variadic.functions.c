// Variadic Functions: Flexible Arguments (Functions that take a variable number of inputs)

#include <stdio.h>   // For printf (printing stuff)
#include <stdarg.h>  // For handling functions with flexible number of arguments (variadic functions)

// formattedString: This function builds a formatted string using a "variable number of inputs".
// Think of it like your customizable Instagram caption — you put in different things, and it builds a message.
void formattedString(char *buffer, const char *format, ...) {
    // va_list is like a magic box that holds all the extra arguments you pass to the function,
    // beyond the fixed ones (buffer and format).
    va_list args;

    // va_start tells the program to start looking inside the magic box (va_list),
    // beginning just after the last named parameter ('format' in this case).
    // Think of the named parameters as the fixed inputs your function always expects,
    // and anything after those is “extra” or optional inputs.
    // So va_start basically says:
    // "Hey args (our magic box pointer), start here — right after 'format' —
    // to find all the extra arguments that were passed in."
    va_start(args, format);


    // vsprintf takes the 'format' string (which is like a template with placeholders like %d or %s),
    // and fills those placeholders with the actual arguments stored inside the magic box (args).
    // The resulting fully built string gets saved into 'buffer'.
    vsprintf(buffer, format, args);

    // va_end cleans up the magic box after we're done grabbing arguments.
    va_end(args);
}

// printNumbers: Prints as many numbers as you want.
// You tell it how many numbers you're going to pass ('count'),
// then it grabs and prints each number one by one.
void printNumbers(int count, ...) {
    va_list args;            // Declare the magic box for extra arguments.
    va_start(args, count);   // Start pointing inside the magic box, right after 'count'.

    for (int i = 0; i < count; i++) {
        // va_arg extracts the next argument from the magic box,
        // and we tell it to expect an int.
        int num = va_arg(args, int);
        printf("%d ", num);  // Print that number.
    }

    va_end(args);            // Clean up when done.
}

// printStrings: Same idea as printNumbers, but for strings.
// You pass any number of strings, and it prints them all.
void printStrings(int count, ...) {
    va_list args;            // Magic box for extra args.
    va_start(args, count);   // Start after 'count'.

    for (int i = 0; i < count; i++) {
        // va_arg extracts the next argument,
        // but this time it expects a pointer to char (string).
        char* str = va_arg(args, char*);
        printf("%s ", str);  // Print the string.
    }

    va_end(args);            // Done, close the box.
}

int main() {
    char output[100];       // This is where your formatted message will live.
    int num = 42;
    float pi = 3.14159;
    char *text = "Hello, World!";

    // Use formattedString to combine different types of values into one neat message.
    // The 'format' string works like a template:
    // - %d means "insert an integer here"
    // - %.2f means "insert a float here with 2 decimal places"
    // - %s means "insert a string here"
    formattedString(output, "Integer: %d, Float: %.2f, String: %s", num, pi, text);

    printf("Formatted string: %s\n", output);  // Shows the combined message.

    printf("\nNumbers: ");
    printNumbers(4, 1, 2, 3, 4);                // Prints: 1 2 3 4

    printf("\nStrings: ");
    printStrings(2, "Hello", "world!");         // Prints: Hello world!

    return 0;   // Done and dusted!
}

// ============================================================
// PHASE 2: Data Types, Variables, Constants
// ============================================================

// A variable in C is a NAMED, FIXED-SIZE region of memory you reserved.
// Ex: "int x;" reserves 4 bytes and calls that spot x. That box has a
// shape now -- permanently, for that variable's lifetime.
// C splits declaration and assignment into two separate steps:
//   int wage;     // declare -- reserve the box
//   wage = 20;    // assign  -- put a value in the box
// C forces this because it needs to know how much space to reserve
// BEFORE it does anything else. C variables ARE the storage (unlike
// Python, where a name just points at an object somewhere else).

// printf format specifiers -- must match the variable's type:
//   %d  ->  int
//   %f  ->  double  (when PRINTING with printf)
//   %lf ->  double  (when READING with scanf)
//   %c  ->  char
// C never adds a newline automatically. If you want one, type \n.

// --- Data types, sizes, and how to write literals ---
// char    [ 1 byte ]  -- a single character. Written with SINGLE quotes:
//                        'A', '7', '$'.  Format specifier: %c
//                        Under the hood it's stored as a small integer
//                        (ASCII code) -- 'A' is stored as 65.
// int     [ 4 bytes ] -- whole numbers, no decimal point. Format: %d
// double  [ 8 bytes ] -- numbers with a fractional part: 3.14, -0.5
//                        Format: %f when printing, %lf when scanning.
//
// IMPORTANT: 'A' (single quotes) = a char.
//            "A" (double quotes) = a string (different, more complex
//            type, covered later -- Lecture 12/13).
//
// Same bits, different interpretation -- the FORMAT SPECIFIER controls
// how printf displays a value, not the data itself:
//   char letter = 'A';
//   printf("%c\n", letter);   // prints: A
//   printf("%d\n", letter);   // prints: 65   (same bits, read as a number)

// %f prints exactly 6 digits after the decimal point by default.
//   e.g. 92.5 printed with %f -> "92.500000"  (NOT "92.5" and NOT
//   a longer string of extra digits)

// EXAMPLE (traced):
#include <stdio.h>

int main(void) {
    int score;       // declares score as an integer
    char grade;       // declares grade as a character
    double average;   // declares average as a double

    score = 85;         // assigns a value
    grade = 'B';         // assigns a value (single quotes -- it's a char)
    average = 92.5;      // assigns a value

    printf("Score: %d\n", score);     // prints: Score: 85
    printf("Grade: %c\n", grade);     // prints: Grade: B
    printf("Average: %f\n", average); // prints: Average: 92.500000
                                        // (NOT 92.5000000000000 -- exactly
                                        // 6 decimal digits, always)
    return 0; // closes the program, tells the OS there's no error
}

// Uninitialized variable = a variable that's been declared but never
// assigned. It is NOT zero/empty -- it holds whatever leftover bits
// happened to already be at that memory address. Reading it doesn't
// crash or throw an error -- it just silently gives garbage output.
// Example of the bug:
//   int score;
//   printf("%d\n", score);   // BUG: score was never assigned yet
//   score = 100;
// Fix: always assign BEFORE you read.
//   int score;
//   score = 100;
//   printf("%d\n", score);   // now prints 100 correctly

// Drill practice (all correct):
//   int x; x = 10; printf("%d\n", x + 5);           -> 15
//   int a,b; a=3; b=a*a; printf("a is %d and b is %d\n", a, b);
//     -> a is 3 and b is 9

// PROGRAMMING ASSIGNMENT -- Student Record
#include <stdio.h>

int main(void) {
    int studentAge;
    char studentGrade;
    double studentGPA;

    studentAge = 20;
    studentGrade = 'A';
    studentGPA = 3.75;

    printf("Age: %d\n", studentAge);
    printf("Grade: %c\n", studentGrade);
    printf("GPA: %f\n", studentGPA);
    // Output:
    // Age: 20
    // Grade: A
    // GPA: 3.750000

    return 0;
}
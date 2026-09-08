// ============================================================
// PHASE 4: More Operators, Math Functions, Random Numbers
// ============================================================

// Compound assignment operators -- shortcut for "update a variable
// based on its own current value":
//   x += 5;   same as   x = x + 5;
//   x -= 3;   same as   x = x - 3;
//   x *= 2;   same as   x = x * 2;
//   x /= 4;   same as   x = x / 4;
//   x %= 3;   same as   x = x % 3;
//
// Increment/decrement -- shortcut specifically for +1 / -1:
//   x++;      same as   x = x + 1;
//   x--;      same as   x = x - 1;
//
// Math functions need #include <math.h>:
//   sqrt(25.0)   -> square root -> 5.0
//   pow(2, 3)    -> 2 raised to power 3 -> 8.0
//   Both return a double, and both expect double arguments (ints get
//   auto-converted).
//
// Random numbers need #include <stdlib.h>:
//   rand()             -> a large random int (0 to some big max)
//   rand() % 10         -> random number 0-9   (modulo restricts range)
//   rand() % 10 + 1      -> random number 1-10  (shift range up)
//   srand()  seeds the random number generator (so you don't get the
//   exact same "random" sequence every run).
//
// IMPORTANT: calling a function like pow(x, y) does NOTHING useful on
// its own if you don't store or use the return value. You must assign
// it: area = pow(radius, 2);  -- not just "pow(radius, 2);" alone,
// which computes a value and then throws it away.

// EXAMPLE (traced):
#include <stdio.h>
#include <math.h>

int main(void) {
    int x;
    double area;

    x = 10;
    x += 5;        // x becomes 15
    x++;            // x becomes 16

    area = pow(4.0, 2.0);   // 4 squared = 16.0

    printf("x is %d\n", x);           // x is 16
    printf("Area is %f\n", area);      // Area is 16.000000

    return 0;
}

// PROGRAMMING ASSIGNMENT -- Circle Calculator
#include <stdio.h>
#include <math.h>

int main(void) {
    double radius, area, circumference;

    radius = 5.0;
    area = 3.14159 * pow(radius, 2);        // pi * r^2
    circumference = 2 * 3.14159 * radius;    // 2 * pi * r

    printf("Area: %f\n", area);                     // Area: 78.539750
    printf("Circumference: %f\n", circumference);     // Circumference: 31.415900

    return 0;
}
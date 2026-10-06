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

#include <stdio.h>

int main(void){
    int total, count;
    total = 17;
    count = 5;

    printf("Quotient: %d\n", total/count);
    printf("Remainder: %d\n", total % count);
    printf("Average: %f\n", (double) total / count);

    return 0;
}

#include <stdio.h>

int main(void){
    double price;
    int quantity;

    printf("Enter a price: ");
    scanf("%lf", &price);

    printf("Enter a quantity: ");
    scanf("%d", &quantity);

    printf("Total: %f\n", price * quantity);

    return 0;
}

#include <stdio.h>

int main(void){
    char c;

    printf("Enter a letter: ");
    scanf(" %c", &c);

    printf("Letter: %c\n", c);
    printf("Code: %d\n", c);
    printf("Next: %c\n", c+1);

    return 0;

}

#include <stdio.h>
#include <math.h>

int main(void){
    int score;
    double side;
    double area;

    score = 80;
    score += 15;
    score ++;

    side = 6.0;
    area = pow(side, 2);

    printf("Score: %d\n", score);
    printf("Area: %f\n", area);
    printf("Root: %f\n", sqrt(area));

    return 0;
}

//Left Number % Right Number
//The left number is what you are dividing into groups.
//The right number  is the size of each group.

#include <stdio.h>
#include <math.h>

int main(void) {
    char initial;
    double a, b, c, d, dx, dy, distance, roundtrip; 
    int seconds;

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter the x and y of the startpoints: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the x and y of the end point: ");
    scanf("%lf %lf", &c, &d);

    printf("Enter the trip time in seconds: ");
    scanf("%d", &seconds);

    printf("Initial: %c\n", initial);
    printf("Code: %d\n", initial);
    printf("Next: %c\n", initial + 1);

    dx = c - a; 
    dy = d - b;

    distance = sqrt(pow(dx, 2) + pow(dy, 2));
    printf("Distance: %f\n", distance);

    roundtrip = distance * 2;
    printf("Roundtrip: %f\n", roundtrip);

    printf("Time: %d minutes %d seconds \n", seconds / 60, seconds % 60);
    printf("Average speed: %f\n", distance / seconds);

    return 0;
}
// ============================================================
// PHASE 3: Operators and Expressions
// ============================================================

// An operator is a symbol that tells the compiler to perform some
// computation on one or more values (called operands).
// Arithmetic operators: + - * / %
//   =  is assignment (not comparison -- that's ==, covered later)
//
// / (division):
//   If BOTH operands are int -> truncates (drops the decimal, does
//   NOT round): 7 / 2 = 3, not 3.5
//   If at least ONE operand is a double -> real decimal division:
//   7.0 / 2 = 3.5,  7 / 2.0 = 3.5
//   IMPORTANT: the type of the DESTINATION VARIABLE does not matter --
//   only the type of the operands being divided matters.
//     double result = 15 / 4;      // still truncates to 3.0 (BUG!)
//     double result = 15.0 / 4;    // correctly gives 3.75
//
// % (modulo) -- gives the REMAINDER of integer division, only works
// between two integers:
//   7 % 2  = 1   (7 = 3*2 + 1)
//   10 % 3 = 1   (10 = 3*3 + 1)
//   9 % 3  = 0   (divides evenly)
//
// Operator precedence (like PEMDAS): * / % happen before + -.
// Parentheses () override everything. Same-precedence ops evaluate
// left to right.
//   Example: 10 + 3*2 - 1/2
//   = 10 + 6 - 0   (1/2 truncates to 0 since both are int!)
//   = 16
//   Example: 20/4 + 3%2*5
//   = 5 + 1*5
//   = 5 + 5 = 10

// EXAMPLE (traced):
#include <stdio.h>

int main(void) {
    int a, b, sum, product, quotient, remainder; // declared all at once

    a = 17;
    b = 5;

    sum = a + b;         // 22
    product = a * b;      // 85
    quotient = a / b;      // 3   (int/int truncates: 17/5 = 3, not 3.4)
    remainder = a % b;      // 2   (17 = 3*5 + 2)

    printf("Sum: %d\n", sum);             // Sum: 22
    printf("Product: %d\n", product);       // Product: 85
    printf("Quotient: %d\n", quotient);       // Quotient: 3
    printf("Remainder: %d\n", remainder);       // Remainder: 2

    return 0;
}

// Drill practice (all correct):
//   15 / 4  -> 3            (int/int truncates)
//   15 % 4  -> 3            (remainder: 15 = 3*4 + 3)
//   double result = 15 / 4;   printed with %f -> 3.000000  (BUG! both
//     operands int, truncates BEFORE ever reaching the double variable)
//   double result = 15.0 / 4; printed with %f -> 3.750000  (correct --
//     one operand is a double, so real division happens)

// PROGRAMMING ASSIGNMENT -- Pizza Slice Calculator
#include <stdio.h>

int main(void) {
    int totalSlices, numPeople, slicesPerPerson, leftoverSlices;
    double avgSlicesDecimal;

    totalSlices = 23;
    numPeople = 5;

    slicesPerPerson = totalSlices / numPeople;    // int/int truncates: 4
    leftoverSlices = totalSlices % numPeople;      // remainder: 3
    // Cast to double so the DIVISION ITSELF is real, not truncated.
    // Casting the destination variable to double is NOT enough --
    // at least one OPERAND in the division must be a double.
    avgSlicesDecimal = (double)totalSlices / numPeople;  // 4.6

    printf("Whole slices per person: %d\n", slicesPerPerson);
    printf("Leftover slices: %d\n", leftoverSlices);
    printf("True average per person: %f\n", avgSlicesDecimal);
    // Output:
    // Whole slices per person: 4
    // Leftover slices: 3
    // True average per person: 4.600000

    return 0;
}
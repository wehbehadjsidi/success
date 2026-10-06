// ============================================================
// PHASE 1: Intro to Computers/Computing (Lecture 1 & 2) + Binary
// ============================================================

// --- Computer hardware, the workshop analogy ---
// CPU (the worker) doesn't store anything long term. It does arithmetic,
// logic, and follows instructions one at a time.
// RAM (the worker's desk) = current project's papers spread out.
// Easy and fast to grab, but the second the power goes off, everything
// on the desk is swept away. "Volatile" = power off, data gone.
// ROM = permanent startup instructions the worker reads every time they
// walk in, that nobody can casually erase. Non-volatile.
// Secondary storage (HDD/SSD) = warehouse out back. Enormous capacity,
// cheap per byte, survives power loss (non-volatile), but slow to access.
// OS = the shift manager: decides who gets desk space (RAM) and when,
// routes messages between the worker and the outside world.
// Application software = a specific task the manager hands the worker.

// Why storage is slow: an SSD/HDD has to locate the right spot, read it,
// and send data over a comparatively slow connection, every time.
// RAM is built to be grabbed instantly, any location, no searching.
// CPUs run billions of operations/sec -- if every op had to reach into
// storage, the CPU would spend nearly all its time waiting.
// System splits the job: storage = permanent but slow, RAM = fast but
// volatile, holding only what's actively being used right now (copied
// over from storage first).

// --- C language facts (Lecture 1) ---
// C was created at Bell Labs by Dennis Ritchie in 1972, on a PDP-11.
// Evolved from an earlier language called B.
// Formalized by ANSI in 1988.
// Runs on ALL of: supercomputers, mainframes, desktops, microcontrollers.
// Used for ALL of: operating systems, compilers, device drivers, databases.
// Every C statement ends in a semicolon.
// The Engineering Problem-Solving Methodology has SIX steps:
//   1. Problem statement
//   2. Describe input/output
//   3. Hand calculations on an example
//   4. Develop an algorithm
//   5. Implement as a C program
//   6. Test the program  <-- LAST step

// Language history pairings (tested directly):
// FORTRAN - John Backus       - scientific/math/statistical computation
// ALGOL   - joint committee   - ancestor of Pascal, C, C++, Java
// LISP    - John McCarthy     - artificial intelligence
// COBOL   - Grace Murray Hopper - business (banking, ATMs)
// BASIC   - Dartmouth students - built for beginners
// Pascal  - Niklaus Wirth     - learning tool for programming
// C       - Dennis Ritchie, Bell Labs - built for/with UNIX

// --- Lecture 2: hardware/software categories ---
// RAM = short-term, read/write, volatile (loses data when powered off)
// ROM = permanent, non-volatile, holds startup instructions
// Secondary storage has MUCH BIGGER capacity than RAM, but is slower.
// System software = OS, drivers, compilers, etc.
// Application software = word processors, games, etc.
// OS's job = manage hardware/software resources, provide common services
// to programs.

// Microcontroller = single IC (integrated circuit) chip with processor +
// memory + I/O all together. Small, self-contained, one chip, one job.
// Cheap and low-power -- found in washing machines, car sensors,
// thermostats, anywhere you need "run this small program forever."
//
// Supercomputer = instead of shrinking onto one chip, thousands of
// separate powerful computers (nodes) wired together with fast
// interconnects, working on one massive problem simultaneously
// (climate modeling, weather forecasting, molecular modeling).

// The Processor (CPU) -- three primary components:
// ALU (Arithmetic and Logic Unit)  -- does the actual math/logic
// Register file -- small set of very fast temp storage slots holding
//   the operands the ALU is actively working with right now
// Control unit -- reads instructions, decides what needs to happen,
//   sends out control signals telling ALU/registers what to do and when

// Low-level vs high-level languages:
// Machine language  = raw 0s and 1s. The ONLY thing the processor's
//   circuitry actually understands and directly executes.
//   (The processor does NOT directly execute high-level code.)
// Assembly language = 1-to-1 human-readable stand-in for machine code
//   (e.g. "ADD A" instead of 00010101). Still tied to one specific
//   processor's exact instruction set -- not portable.
// High-level language (C, Python) = abstracted from hardware details,
//   PORTABLE -- runs anywhere a compiler exists for that platform.

// Toolchain to build an executable, in order:
// Compiler (HLL -> assembly) -> Assembler (assembly -> machine code,
// produces the OBJECT FILE) -> Linker (combines object files + libraries
// into one executable) -> Loader (puts the executable INTO MEMORY,
// ready to run).

// Machine cycle: always 3 steps, in this order:
// IF (Instruction Fetch) -> ID (Instruction Decode) -> EX (Execute)

// Hex/binary fact: each hex digit = exactly 4 binary bits (16 = 2^4).

// --- Binary (2.6) ---
// Binary is just a different counting system than decimal.
// Decimal (base 10): 10 digits (0-9), each position is a power of 10.
//   Example: 212 = 2*10^2 + 1*10^1 + 2*10^0 = 200 + 10 + 2 = 212
// A computer can't reliably represent 10 distinct voltage levels, but
// CAN reliably tell "on" from "off" -- two states. So computers use
// base 2 (binary): only digits {0,1}, each position is a power of 2.
// Memory is literally built from switches (transistors) that are
// either on or off, so everything is encoded as 0s and 1s.

// BINARY -> DECIMAL (multiply each bit by its position value, add up):
//   11010100 = 1*128 + 1*64 + 0*32 + 1*16 + 0*8 + 1*4 + 0*2 + 0*1 = 212
// Shortcut: skip the 0-bits entirely, only add up positions where bit=1.
//
// Example: 00001111
//   1s are at positions 2^3,2^2,2^1,2^0 = 8,4,2,1 -> 8+4+2+1 = 15
//
// Example: 10001000 (must count positions from the RIGHT, position 0
// starts at the rightmost bit -- don't just grab "however many 1s"):
//   Binary:   1   0   0   0   1   0   0   0
//   Position: 2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
//   Value:    128 64  32  16  8   4   2   1
//   1s are at 2^7(128) and 2^3(8) -> 128 + 8 = 136

// DECIMAL -> BINARY (greedy fit-and-subtract method):
// At each step, starting from the largest power of 2: check if that
// power of 2 is LESS THAN OR EQUAL TO what's currently left to build.
//   If YES -> bit = 1, subtract that power from what's left.
//   If NO  -> bit = 0, what's left stays unchanged.
// Repeat down to 2^0. (Equal counts as "fits" -- e.g. 4 fits into 4.)
//
// Example: convert 11 to 4-bit binary (powers: 8,4,2,1)
//   Does 8 fit into 11? Yes (8<=11) -> bit=1, left = 11-8 = 3
//   Does 4 fit into 3?  No  (4>3)   -> bit=0, left stays 3
//   Does 2 fit into 3?  Yes (2<=3)  -> bit=1, left = 3-2 = 1
//   Does 1 fit into 1?  Yes (1<=1)  -> bit=1, left = 1-1 = 0
//   Result: 1011   Check: 8+0+2+1 = 11 correct
//
// Example: convert 6 to 4-bit binary (powers: 8,4,2,1)
//   Does 8 fit into 6? No  -> bit=0
//   Does 4 fit into 6? Yes -> bit=1, left = 6-4 = 2
//   Does 2 fit into 2? Yes -> bit=1, left = 2-2 = 0
//   Does 1 fit into 0? No  -> bit=0
//   Result: 0110   Check: 4+2 = 6 correct
//
// Example: convert 17 to 8-bit binary (powers: 128,64,32,16,8,4,2,1)
//   Does 128 fit into 17? No -> 0
//   Does 64 fit into 17?  No -> 0
//   Does 32 fit into 17?  No -> 0
//   Does 16 fit into 17?  Yes -> bit=1, left = 17-16 = 1
//   Does 8 fit into 1?    No -> 0
//   Does 4 fit into 1?    No -> 0
//   Does 2 fit into 1?    No -> 0
//   Does 1 fit into 1?    Yes -> bit=1, left = 0
//   Result: 00010001   Check: 16+1 = 17 correct


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
//   Both return a double.
//
// Random numbers need #include <stdlib.h>:
//   rand()             -> a large random int (0 to some big max)
//   rand() % 10         -> random number 0-9   (modulo restricts range)
//   rand() % 10 + 1      -> random number 1-10  (shift range up)
//
// IMPORTANT: calling a function like pow(x, y) does NOTHING useful on
// its own if you don't store or use the return value. You must assign
// it: area = pow(radius, 2);  -- not just "pow(radius, 2);" alone.

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


// ============================================================
// PHASE 5: Program I/O (printf, scanf, fgetc, fgets) -- IN PROGRESS
// ============================================================

// scanf reads input FROM the keyboard INTO a variable.
// & (address-of operator): &variableName means "the memory ADDRESS of
// this variable," not its value. scanf needs to know WHERE in memory
// to write the value the user types -- like giving someone your house
// address so they can deliver a package, instead of just describing
// what's already inside your house. printf only needs the VALUE
// (it's just reading/displaying); scanf needs the ADDRESS (it's writing
// something new into memory).

// Reading an int:
//   int age;
//   scanf("%d", &age);

// Reading a double -- note the specifier DIFFERS from printing!
//   double price;
//   scanf("%lf", &price);   // %lf for scanf, but %f for printf

// Reading a char -- THE GOTCHA:
//   char letter;
//   scanf(" %c", &letter);   // notice the SPACE before %c
// Why the space: pressing Enter after typing leaves a leftover newline
// character sitting in the input buffer. %d and %lf automatically skip
// leading whitespace before reading, but %c does NOT -- without the
// leading space, %c can accidentally grab that leftover newline instead
// of the actual character you wanted. This matters most when reading
// multiple chars in a row (exactly what Lab 2 Part 2 needs).

// Reading multiple values in one scanf call:
//   int x, y;
//   scanf("%d %d", &x, &y);
// User can type them space-separated or on separate lines -- scanf
// treats whitespace between numeric inputs as interchangeable.

// NOTE: scanf itself does not print anything. Anything you see echoed
// back after a prompt (like "12" after "Enter an integer value: ") is
// just the terminal showing what the USER typed, not something the
// program printed.

// EXAMPLE (traced) -- this is essentially Lab 2 Part 1's exact shape:
#include <stdio.h>

int main(void) {
    int num1, num2, sum;

    printf("Enter an integer value: ");
    scanf("%d", &num1);

    printf("Enter another integer value: ");
    scanf("%d", &num2);

    sum = num1 + num2;

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    // If user types 12 then 35:
    // Enter an integer value: 12
    // Enter another integer value: 35
    // The sum of 12 and 35 is 47.

    return 0;
}

// STILL TO COVER before Lab 2 is fully ready:
// - Reading multiple chars in a row correctly (the " %c" trick applied
//   in sequence -- this is exactly what Lab 2 Part 2 needs)
// - fgetc and fgets (not yet covered)
#include <iostream>

using namespace std;

const long MAX = 1000000;   // Numbers from 1 to MAX - 1 (inclusive) will be evaluated.
long lengths[MAX];          // Array of lengths from each number to 1 through the collatz chain.
void initialize();          // Initialize the array of lengths with the default value of -1.
long setLength(long n);     // Sets the length of the number from n to 1 through the collatz chain.
long getLongest();          // Gets number below MAX that produces the longest collatz chain.

int main() {
    long longest;
    initialize();
    longest = getLongest();
    cout << longest;
}

void initialize() {
    for (long i = 1; i < MAX; i++)
        lengths[i] = -1;
    for (long i = 1; i < MAX; i++)
        setLength(i);
}

long setLength(long n) {
    // Base case.
    if (n == 1)
        return lengths[n] = 0;
    long collatz = n % 2 ? 3 * n + 1 : n / 2;
    // N in array range.
    if (n < MAX)
        return lengths[n] = 1 + setLength(collatz);
    // N not in range.
    return 1 + setLength(collatz);
}

long getLongest() {
    long longest = 1;
    for (long i = 1; i < MAX; i++)
        if(lengths[longest] < lengths[i])
            longest = i;
    return longest;
}

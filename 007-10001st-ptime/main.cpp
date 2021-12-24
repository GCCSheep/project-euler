#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n);

int main() {
    int n = 2;
    for (int i = 0; i < 10001; n++) {
        if (isPrime(n))
            i++;
    }
    cout << n - 1;
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

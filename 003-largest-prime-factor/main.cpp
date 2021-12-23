#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long n);

int main() {
    long n = 600851475143;
    for (long i = n; i > 2; i = n / (n / i + 1))
        if (n % i == 0 && isPrime(i)) {
            cout << i;
            break;
        }
}

bool isPrime(long n) {
    for (long i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return n > 1;
}

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long n);

int main() {
    long sum = 0;
    for (int i = 2; i < 2000000; i++)
        if (isPrime(i))
            sum += i;
    cout << sum;
}

bool isPrime(long n) {
    for (long i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return n > 1;
}

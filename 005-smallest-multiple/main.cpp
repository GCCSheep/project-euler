#include <iostream>
#include <string>

using namespace std;

void factorize(int* factors, int n);
void initialize(int* arr);
int multiply(int* factors);
const int n = 20;

int main() {
    int smallest[n + 1];
    initialize(smallest);
    for (int i = 2; i < n + 1; i++) {
        int factors[n + 1];
        factorize(factors, i);
        for (int j = 2; j < n + 1; j++)
            if(smallest[j] < factors[j])
                smallest[j] = factors[j];
    }
    cout << multiply(smallest);
}

void factorize(int* factors, int n) {
    initialize(factors);
    for (int i = 2; i <= n + 1; i++)
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
}

void initialize(int* arr) {
    for (int i = 0; i < n + 1; i++)
        arr[i] = 0;
}

int multiply(int* factors) {
    int product = 1;
    for (int i = 2; i < n + 1; i++)
        for (int j = 1; j <= factors[i]; j++)
            product *= i;
    return product;
}

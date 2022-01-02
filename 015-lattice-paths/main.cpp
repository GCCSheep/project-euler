#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 40;
vector<int> factorize(int n);
vector<int> multiply(vector<int> v1, vector<int> v2);
vector<int> divide(vector<int> v1, vector<int> v2);
vector<int> factorial(int n);
long toNumber(vector<int> factors);
void print(vector<int> factors);

int main() {
    const vector<int> num = factorial(40);
    const vector<int> denom = multiply(factorial(20), factorial(20));
    cout << toNumber(divide(num, denom));
}

// Returns factorized form of the number.
vector<int> factorize(int n) {
    vector<int> factors(MAX + 1);
    for (int i = 0; i < factors.size(); i++) {
        factors[i] = 0;
        if (i <= 1)
            continue;
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    return factors;
}

// Multiplies factorized forms of the numbers.
vector<int> multiply(vector<int> v1, vector<int> v2) {
    vector<int> result(MAX + 1);
    for (int i = 0; i < result.size(); i++)
        result[i] = v1[i] + v2[i];
    return result;
}

// Divides factorized forms of the numbers. Assumes v1 > v2.
vector<int> divide(vector<int> v1, vector<int> v2) {
    vector<int> result(MAX + 1);
    for (int i = 0; i < result.size(); i++)
        result[i] = v1[i] - v2[i];
    return result;
}

// Returns factorial of a number in its factorized form.
vector<int> factorial(int n) {
    vector<int> result = factorize(n);
    for (int i = n - 1; i > 0; i--)
        result = multiply(result, factorize(i));
    return result;
}

// Returns prodcut of the factorization of a number.
long toNumber(vector<int> factors) {
    long result = 1;
    for (int i = 0; i < factors.size(); i++)
        if (factors[i] != 0)
            result *= pow(i, factors[i]);
    return result;
}

// Print factorized form of the number.
void print(vector<int> factors) {
    for (int i = 0; i < factors.size(); i++)
        if (factors[i])
            cout << i << ": " << factors[i] << endl;
    cout << endl;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int n = 10000;
vector<int> propSums(n);    // Store the proper sums of numbers.
vector<int> amicables;      // Defines whether a number is amicable or not.
void initPropSums();
int propSum(int n);
void initAmicables();
bool amicable(int a, int b);
bool contains(vector<int> v, int n);
int sumAmicables();
void print(vector<int> v);

int main() {
    initPropSums();
    initAmicables();
    cout << sumAmicables();
}

// Initialize sums of proper divisors for all numbers up to n.
void initPropSums() {
    for (int i = 0; i < propSums.size(); i++)
        propSums[i] = propSum(i);
}

// Sum the proper divisors of n.
int propSum(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int sum = 0;
    for (int i = 1, limit = n / 2; i <= limit; i++)
        if (n % i == 0)
            sum += i;
    return sum;
}

// Initialize amicable numbers.
void initAmicables() {
    for (int i = 0; i < propSums.size(); i++)
        for (int j = 0; j < propSums.size(); j++)
            if (amicable(i, j)) {
                // Skip elements already found to be amicables.
                if (!contains(amicables, i))
                    amicables.push_back(i);
                if (!contains(amicables, j))
                    amicables.push_back(j);
                break;
            }
}

// Returns whether or not pair of numbers is amicable.
bool amicable(int a, int b) {
    return a != b && propSums[a] == b && a == propSums[b];
}

// Return whether or not vector contains element.
bool contains(vector<int> v, int n) {
    return find(v.begin(), v.end(), n) != v.end();
}

// Sum all amicables < n.
int sumAmicables() {
    int sum = 0;
    for (int n : amicables)
        sum += n;
    return sum;
}

// Print given vector.
void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << i << ": " << v[i] << endl;
    cout << endl;
}

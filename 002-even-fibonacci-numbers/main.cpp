#include <iostream>

using namespace std;

int main() {
    int sum = 2;
    for (int f0 = 1, f1 = 2, f2 = f0 + f1; f2 < 4000000; f0 = f1, f1 = f2, f2 = f0 + f1)
        if (f2 % 2 == 0)
            sum += f2;
    cout << sum;
}

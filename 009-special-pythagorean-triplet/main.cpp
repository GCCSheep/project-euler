#include <iostream>

using namespace std;

int main() {
    int a, b, c, n = 1000;
    bool found = false;
    for (c = 1; c < n && !found; c++)
        for (b = 1; b < c && !found; b++)
            for (a = 1; a < b && !found; a++)
                if (a * a + b * b == c * c && a + b + c == n)
                    found = true;
    cout << (a - 1) * (b - 1) * (c - 1);
}

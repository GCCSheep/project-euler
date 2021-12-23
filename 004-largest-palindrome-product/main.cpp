#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s);

int main() {
    int largest = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = 100; j <= i; j++) {
            int product = i * j;
            if (isPalindrome(to_string(product)) && product > largest)
                largest = product;
        }
    cout << largest;
}

bool isPalindrome(string s) {
    for (int i = 0; i <= s.length() / 2 + 1; i++)
        if (s[i] != s[s.length() - 1 - i])
            return false;
    return true;
}

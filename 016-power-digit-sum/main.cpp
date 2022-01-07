#include <iostream>
#include <string>

using namespace std;

string add(string s1, string s2);
string multiply(string s, int n);
string power(string s, int n);
int sumDigits(string s);

int main() {
    cout << sumDigits(power("2", 1000));
}

// Adds 2 numbers in the form of strings. Assumes digits only.
string add(string s1, string s2) {
    string sum = "";
    int deltaLen = s1.length() - s2.length();
    // Makes sure the strings are the same length by adding left zeroes.
    if (deltaLen > 0)
        s2.insert(0, deltaLen, '0');
    else if (deltaLen < 0)
        s1.insert(0, -deltaLen, '0');
    // Iterates on each digit, from right to left.
    for (int i = s1.length() - 1, carry = 0, partialSum; i >= 0; i--) {
        partialSum = (s1[i] - '0' + s2[i] - '0') % 10 + carry;
        carry = (s1[i] - '0' + s2[i] - '0') / 10;
        sum.insert(0, 1, (char)(partialSum + '0'));
        if (i == 0 && carry == 1)
            sum.insert(0, 1, '1');
    }
    return sum;
}

// Multiplies the number stored in "s", by "n".
string multiply(string s, int n) {
    string prod = s;
    for (int i = 1; i < n; i++)
        prod = add(prod, s);
    return prod;
}

// Raises number stored in "s" to the nth power.
string power(string s, int n) {
    string pwr = s;
    for (int i = 1; i < n; i++)
        pwr = multiply(pwr, stoi(s));
    return pwr;
}

// Sum digits of the numeric string.
int sumDigits(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += s[i] - '0';
    return sum;
}

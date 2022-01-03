#include <iostream>
#include <string>

using namespace std;

string toString(int n);

int main() {
    int count = 0;
    for (int i = 1; i <= 1000; i++)
        count += toString(i).length();
    cout << count;
}

string toString(int n) {
    string s = "";
    int hundreds = n / 100;
    int tens = (n % 100) / 10;
    int ones = n % 10;
    if (n / 1000)
        return "onethousand";
    if (hundreds) {
        switch (hundreds) {
        case 1: s += "one"; break;
        case 2: s += "two"; break;
        case 3: s += "three"; break;
        case 4: s += "four"; break;
        case 5: s += "five"; break;
        case 6: s += "six"; break;
        case 7: s += "seven"; break;
        case 8: s += "eight"; break;
        case 9: s += "nine"; break;
        }
        s += "hundred";
    }
    if (tens) {
        if (hundreds)
            s += "and";
        switch (tens) {
        case 1:
            switch (ones) {
            case 0: s += "ten"; break;
            case 1: s += "eleven"; break;
            case 2: s += "twelve"; break;
            case 3: s += "thirteen"; break;
            case 4: s += "fourteen"; break;
            case 5: s += "fifteen"; break;
            case 6: s += "sixteen"; break;
            case 7: s += "seventeen"; break;
            case 8: s += "eighteen"; break;
            case 9: s += "nineteen"; break;
            }
            break;
        case 2: s += "twenty"; break;
        case 3: s += "thirty"; break;
        case 4: s += "forty"; break;
        case 5: s += "fifty"; break;
        case 6: s += "sixty"; break;
        case 7: s += "seventy"; break;
        case 8: s += "eighty"; break;
        case 9: s += "ninety"; break;
        }
    }
    if (tens != 1 && ones) {
        if (hundreds && !tens)
            s += "and";
        switch (ones) {
        case 1: s += "one"; break;
        case 2: s += "two"; break;
        case 3: s += "three"; break;
        case 4: s += "four"; break;
        case 5: s += "five"; break;
        case 6: s += "six"; break;
        case 7: s += "seven"; break;
        case 8: s += "eight"; break;
        case 9: s += "nine"; break;
        }
    }
    return s;
}

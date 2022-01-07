#include <iostream>
#include <string>

using namespace std;

string nextDate(string date);

int main() {
    int sundays = 0;    // Sundays that fell on the first of the month
    int dow = 3;        // Day of the week
    for (   string date = "19010101";
            date != "20010101";
            date = nextDate(date), dow = dow % 7 + 1)
        if (dow == 1 && date.substr(6, 2) == "01")
            sundays++;
    cout << sundays;
}

string nextDate(string date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(4, 2));
    int d = stoi(date.substr(6, 2));
    int maxDays;
    // Set max. number of days for a month.
    switch (m) {
        // Month has 31 days.
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxDays = 31;
            break;
        // Month has 30 days.
        case 4:
        case 6:
        case 9:
        case 11:
            maxDays = 30;
            break;
        case 2:
            // Feb has 28/29 days on regular/leap years.
            if (y % 400 == 0)
                maxDays = 29;
            else if (y % 100 == 0)
                maxDays = 28;
            else if (y % 4 == 0)
                maxDays = 29;
            else
                maxDays = 28;
            break;
        default:
            cout << "Invalid month." << endl;
            exit(1);
    }
    // Set date, numerically.
    if (d < maxDays)
        d++;
    else {
        d = 1;
        if (m < 12)
            m++;
        else {
            m = 1;
            y++;
        }
    }
    // Set date string.
    string yStr = to_string(y);
    string mStr = (m < 10 ? "0" : "") + to_string(m);
    string dStr = (d < 10 ? "0" : "") + to_string(d);
    return yStr + mStr + dStr;
}
